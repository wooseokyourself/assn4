#ifndef __AS4_MODEL_SEQ_H
#define __AS4_MODEL_SEQ_H

#include <vector>
#include "model/note.h"
#include "model/time.h"

namespace as4::model
{
    /**
     * Abstract)
     * Abstract class for any note sequence
     *
     * Note)
     * Why would we want to use this useless class without any implementation?
     *
     * If you read "io/seqio.h" or some test codes provided with this project,
     * you'll notice that when they take any note sequence as parameters,
     * they are always using 'ISeq', not VectorSeq or something.
     *
     * As far as the method definitions of ISeq stay still, I can write any
     * code that uses note sequence, even without a single implementation.
     *
     * As a TA, this is a good thing because I can write test codes without
     * considering how you implemented details.
     *
     * In real projects, you can prepare multiple implementations for a single
     * abstract class (interface) and use different implementation for
     * different situations
     */
    class ISeq
    {
        public:
            ISeq();
            ISeq(const ISeq &other);
            /** Define virtual destructor for abstract class */
            ~ISeq();
            /**
             * Abstract)
             * Puts a new note into the sequence
             * 
             * @param note          a Note object to be put
             */

            ISeq& operator=(const ISeq &other);

            void Put(const Note &note);

            /**
             * Abstract)
             * Get all notes that starts at or is playing at seeker position.
             *
             * Note)
             * There can be multiple notes to be played given a seeker position.
             * There are multiple notes with same start timestamps (Polyphony)
             *
             * Returns)
             * Pointers to Notes to be played. The lifetime of this pointers are
             * equal to this object's.
             */
            std::vector<Note*> Get(const Timestamp &pos_seeker);

            /**
             * Abstract)
             * Remove a note from the sequence
             *
             * Returns)
             * True if a note is removed. False if the note did not exist.
             */
            bool Remove(const Note *note);

            /**
             * Abstract)
             * Get ordered vector of notes.
             *
             * Note)
             * The first elements of the vector has the earliest start time.
             *
             * Returns)
             * Pointers to all notes in ascending order of start time
             */
            std::vector<Note*> GetOrdered();

            /**
             * Abstract)
             * Get time length of this sequence.
             *
             * Note)
             * Length of a sequence is defined by the max value of start time
             * plus duration of the note.
             */
            TimeInterval GetSeqTimeLength() const;

            int getSize() const{
                return m_notes.size();
            }

            Note* operator[] (int idx);

            bool operator== (const ISeq& other) const;

            void PopBack();


    private:
        void Sort();

        std::vector<Note*> m_notes;
    };

    // You can remove this default implementation if you want.
    // You might want to use different underlying implementation for ISeq
    //
    // Right now, it uses std::list of Note as container for notes
    // Is this the best way you can go with? (If it works, it doesn't matter)
    // There will be no additional credit for this change.
    //
    // Hint : std::priority_queue


    // If you want to use your implementation in test_model.cpp and song.h,
    // change 'VectorSeq' to something else
    using DefaultSeq = ISeq;
}

#endif
