# assn4
5.2 (D-9)
-
드디어 창을 띄웠음 >> mainwindow.ui
기존 과제는 QWidget 을 상속받아 메인윈도우를 띄웠는데, 나는 QMainWindow로 고쳐서 상속받아서 띄웠음.
왜냐하면 QWidget일 경우, 파일시스템이 어떤 식으로 돌아가는지 모르기 때문.
Problem1 에서, 두 ISeq 간의 비교연산을 진행하는 QCOMPARE을 구현해야 함.
사실 Problem1 제대로 동작하는지도 불분명.

-----

5.3 (D-8)
-
Problem 1 완료; song 의 <<, >>, == operator 는 seq의 operator 만으로 구현이 가능할 줄 알았으나 불가능하여(물론 가능한 방법이 존재하긴 하겠지만) song의 operator를 따로 구현해줌.
ui에서 .qrc 에서의 파일을 못 가져옴. ui 에디터 안에서는 분명히 뜨는데 실행시키면 안 뜸. 똑같은 과정이 새 프로젝트에서 되는 걸로 보아 현재 과제 프로젝트에 설정문제가 있는 듯 하나 진짜 찾을 자신이 1도 없음.


-----

5.4 (D-7)
-
과제 처음부터 mainwindow 소스가 as4.pro에 있길래 as4.pro 안에 .ui를 만들고 이리저리 생쇼를 했는데, 오늘 편의점 알바를 하던 도중 .ui는 as4가 아닌 app.pro에 넣어야 한다고 공지가 올라옴(이제서야?) 지금까지의 삽질은 정말 헛된 삽질이었음 안 알려줬으면 과제제출 절대못했음. 근데 이건 학생들이 하도 문의메일을 많이 해서 공지로 올려주신 걸테니, 나 말고도 수 많은 학생들이 나와 공통된 문제로 삽질을 해왔던 게 분명함. 

어쨌거나 오늘은 UI 초안을 만들었고, 스켈레톤 분석함; 
 - start와 duration의 자료형인 TimeInterval 과 TimeStamp 는 동일한 자료형임(unsigned long long)
 - 각 노트는 (TimeStamp start, TimeInterval duration, Pitch(int pitch, int octave))
 - 1 TimeInterval = 0.5 beat = 2unit = "0.25sec"
 
 앞으로는...
  >> 마우스클릭으로 노트를 삽입하고 삭제하는 GUI 구현해야 함.
  
  >> 이 때, 노트가 삽입되면 ISeq::vector<Note*> m_notes 에 삽입된 노트의 위치를 토대로 새 Note push_back
  
  >> 이런 식으로 실시간으로 형성되는 melody sequence와 drum sequence를 Song 객체가 가지고 있어야 하며,
  
  >> UI에서 PLAY 버튼 누를 시 이 Song 객체에 저장된 정보를 토대로 resource의 .wav 플레이하는 클래스를 구현해야함


-----
5.5 (D-6)
- 
노트삽입 gui를 구현하기 위해 QLabel을 상속하는 ClickableLabel 클래스 구현하여 그걸로 피아노롤 이미지를 띄움. (기존 QLabel에는 클릭 시그널이 없음)

두 개의 ClickableLabel이 각각 탭위젯의 탭1, 탭2 객체를 상속하며 멜로디, 드럼 피아노롤을 구현함.

이후 마우스 클릭을 시그널로 노트를 생성 및 제거. 이 때, 노트객체 역시 자신의 위치정보를 저장하고 있어야 하므로 QLabel을 상속하는 VisualNote 클래스를 구현함.

x, y를 계산하는 데 기초적인 수학적인 계산이 들어갔으며, 이 x와 y의 위치를 토대로 노트의 삽입과 제거가 이루어짐.

그러나 현재 노트의 제거 도중 세그먼트에러가 발생하는 것 같음. 다시 봐야함.


-----
5.6 (D-5)
-
1차

모든 GUI 구현 완료, mainwindow 에서 노트의 비주얼 저장하는 VisualNote의 시퀀스를 std::vector 에서 QVector 로 변경함.

QVector을 melody용과 drum용 두 개로 나눔. UI에 보이고 삭제되는 시그널과 슬롯 역시 melody용과 drum용 두 개로 나눔.

앞으로 노트 추가 및 제거에서 노트의 위치를 담고있는 pos를 토대로 ISeq에 노트가 삽입되어야 함. 그렇게 하기 위해 pos와 (start, duration, Pitch) 를 매핑하는 공식이 필요함.

 > 애초에, VisualNote를 기존에 제공받은 Note클래스를 상속받아서 구현하면 더 깔끔하지 않을까?
  -> 굳이 그럴 필요가 없음. 게다가 아직은 slot과 signal 없이 메소드호출만으로 충분히 구현 가능하여 그렇게 구현함.

2차

pos와 Note 매핑하는 공식 적용 완료, Note 클래스의 == 연산자 통해 적용함.

매핑을 위해서는 mainwindow::Put , mainwindow::Remove 메소드에서 pos의 x, y값이 roughValue / 24(1unit의 길이) 로 계산되어

0 또는 0보다 큰 정수로 전달되어야 함에 유의. (이 때, roughValue란 순수히 마우스의 클릭만으로 얻어진 초기값)

Put에서는 이렇게 계산된 값이 int x, int y 이고 Remove에서는 int _x, int_y 임.

이제 FullSong 객체를 토대로 .wav 리소스 파일들을 알맞게 저장하고, 그것들을 재생하는 클래스를 구현하고

Play 버튼의 시그널로 그 클래스의 슬롯을 호출하여 음악이 재생되는 기능만 구현하면 됨.


-----
5.9 (D-2)
-
1차 

대부분 구현 완료

; PlaySong 객체에서 현재 탭 위젯을 기준으로 DefaultTrack, DrumTrack 중에서 하나 생성함. 여기서 지지고 볶고 재생

; QSoundEffect를 상속하는 AutoStopSoundEffect 클래스 구현함. 이를 통해 각 노트의 재생시간 설정 가능해짐.

추가 구현해야 할 사항 : Drum의 AutoStopSoundEffect에는 Duration을 현재 소스의 wav파일 길이만큼으로 받아와야 하는 기능이 들어가야함

한 트랙의 재생(5초)이 완료되면(즉, 트랙재생 타이머의 timeInterval(5000) 이 끝나면) 프로그램 튕김. 이거고쳐야함

2차

이거 나중에 다시 가져올 때 song.h 에서 클래스 내 생성자 선언 지워야함.

끝!!
-


-----
5.10 (D-1 -> D-8)
-
QUIT 버튼 생성, 디버깅용 코드 모두 제거

디버깅용은 아이클라우드에 저장해둠

포스텍 축제라고 갑자기 기간 일주일 늘려주심(...) 
