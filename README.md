# UE5_KawaiPattern

## 언리얼 엔진 버전
- 5.1.1 (VS 2022 Community)



## 언리얼 엔진 초기 세팅

- 



## 기본 베이스 코드
- 이득우 언리얼 part2 코드



## 레퍼런스
- 렘넌트2 보스전 세미 구현



## 최소 사양
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