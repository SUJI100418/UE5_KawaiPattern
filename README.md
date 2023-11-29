# UE5_KawaiPattern

## 언리얼 엔진 버전
- 5.1.1 (VS 2022 Community)



## 언리얼 엔진 초기 세팅

- 



## 기본 베이스 코드
- 이득우 언리얼 part3 코드



## 레퍼런스
- 렘넌트2 보스전 세미 구현



## 최소 사양
- 2인 멀티 입장 및 이동, 공격 동기화
- 보스 AI 한마리 구현
- 아이템 (무기) 구현
- UI 구현



------------------------------

## push 전, 지워도 되는 폴더
1. .vs : (숨김 설정) Generate Visual Studio Project 하면 다시 생성
2. Binaries : 지워도 uproject 파일 실행 시, missing - Yes 누르면 다시 생성
3. DerivedDataCache : 중간 파일과 캐시 데이터 저장 폴더
4. Intermediate : 빌드 시 생성되는 중간 파일 위치
5. .vsconfig : VS에서 사용되는 파일
6. .sln : VS 솔루션 파일

(지우면 안되는 폴더)
1. Config : 언리얼 환경설정 파일
2. Content : 에셋
3. Saved : 프로젝트 작업 중 생성되는 임시 파일
4. Source : C++ 코드
5. .uproject : 엔진 프로젝트, 더블 클릭하여 실행

-------------------------------

## 언리얼 단축키
### VS
- Ctrl + Shift + B : VS 컴파일 (Build: 1 succeeded 체크)
- Ctrl + F5 : 에디터 실행

### 에디터
- Shift + F1 : 플레이 상태에서 마우스 뺌





-------------------------------

### 언리얼 멀티플을 위한 설정
https://docs.unrealengine.com/5.3/en-US/networking-overview-for-unreal-engine/

- 실행 옵션 (실행 아이콘 옆에 ... 세로로 있는 버튼)
    - Net Mode -> **Player As Listen Server**
    - Selected Viewport 체크 ON
    - Advanced Settings -> Always On Top 체크 ON

- Editor Preferences
    - join : Allow late joining 체크 ON
