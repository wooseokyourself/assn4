#include <algorithm>
#include <iostream>
#include "model/seq.h"

namespace as4::model
{
    ISeq::ISeq()
    {   }

    ISeq::~ISeq()
    {
        for(size_t i=0; i<m_notes.size(); i++)
        {
            delete m_notes[i];
        }
    }

    ISeq::ISeq(const ISeq &other)
    {
        for(size_t i=0; i<other.m_notes.size(); i++)
        {
            m_notes.push_back(new Note(*other.m_notes[i]));
        }
    }

    ISeq &ISeq::operator=(const ISeq &other)
    {
        for(size_t i=0; i<m_notes.size(); i++)
        {
            delete m_notes[i];
        }
        m_notes.clear();

        for(size_t i=0; i<other.m_notes.size(); i++)
        {
            m_notes.push_back(new Note(*other.m_notes[i]));
        }

        return *this;
    }

    void ISeq::Put(const Note &note)
    {
        m_notes.push_back(new Note(note));
        // Since we use a simple vector,
        // we must sort the vector everytime we modify m_notes
        Sort();
    }

    std::vector<Note*> ISeq::Get(const Timestamp &pos_seeker)
    {
        std::vector<Note*> result;
        for(size_t i=0; i<m_notes.size(); i++)
        {
            Timestamp start = m_notes[i]->GetStart();
            Timestamp end = start+m_notes[i]->GetDuration();
            if (start <= pos_seeker && end > pos_seeker)
            {
                result.push_back(m_notes[i]);
            }
        }

        return result;
    }

    bool ISeq::Remove(const Note *note)
    {
        const auto target =
                std::find(std::begin(m_notes), std::end(m_notes), note);
        if(std::end(m_notes) != target) // remove target found
        {
            m_notes.erase(target);
            // Since we use a simple vector,
            // we must sort the vector everytime we modify m_notes
            Sort();
            return true;
        }
        else { // not found
            return false;
        }
    }

    std::vector<Note*> ISeq::GetOrdered()
    {
        // Just copy notes directly since they are already ordered
        return m_notes;
    }

    TimeInterval ISeq::GetSeqTimeLength() const
    {
        if(0 == m_notes.size())
        {
            return 0;
        }
        else {
            return m_notes.back()->GetStart() +
                    m_notes.back()->GetDuration();
        }
    }

    void ISeq::Sort()
    {
        // sort m_notes according to start time of each note
        std::sort(std::begin(m_notes), std::end(m_notes),
                [](const Note *a, const Note *b){
            return a->GetStart() < b->GetStart(); });
    }

    Note* ISeq::operator[] (int idx){
        return m_notes[idx];
    }

    bool ISeq::operator== (const ISeq& other) const
    {
        //std::cout<<" >> 시퀀스 == 연산자 작동!"<<std::endl;
        if(m_notes.size()!=other.getSize()){
        //    std::cout<<" >> return false; 두 시퀀스의 size가 다릅니다("<<m_notes.size()<<"/"<<other.getSize()<<")."<<std::endl;
            return false;
        }

        else{
            for(int i=0; i<m_notes.size(); i++){
                if(m_notes[i]->GetStart() != other.m_notes[i]->GetStart() ||
                   m_notes[i]->GetDuration() != other.m_notes[i]->GetDuration() ||
                   m_notes[i]->GetPitch().GetPitchClass() != other.m_notes[i]->GetPitch().GetPitchClass() ||
                   m_notes[i]->GetPitch().GetOctave() != other.m_notes[i]->GetPitch().GetOctave()){
                   //std::cout<<" >> return false; 두 시퀀스의 내용이 다릅니다."<<std::endl;
                   return false;
                }
            }
        }
        return true;
    }

    void ISeq::PopBack(){
        m_notes.pop_back();
    }

}
