# DMOJ 보충 설명
### 구조
사용자 <-> Site <-> Judge  
=========\\--관리자--/
* Site에 문제를 등록하면 Judge에 해당 문제의 채점 파일(ex. txt 파일)이 들어있어야 채점이 가능합니다.
* [DMOJ Docs](https://dmoj.readthedocs.io/) 해당 사이트 반드시 참고하면서 보셔야 합니다.
### 1. 설치
#### Site
* Installing the prerequisites
  - node 버전은 8.x로도 가능합니다. 가급적이면 최신 버전을 사용해주시기 바랍니다.
* Creating the database
  - `wget http://dev.mysql.com/get/mysql-apt-config_0.8.10-1_all.deb` 으로 하길 권장합니다. 버전이 판올림되었습니다.
* Installing prerequisites
  - DMOJ가 사용하는 python 버전은 2.x 대임을 유의하시길 바랍니다. 만약 2.x대와 3.x대가 같이 설치되어 있다면 `virtualenv`를 생성할 때 `virtualenv --python=/usr/bin/python2.6 <path/to/new/virtualenv/>`로 하시면 됩니다.
* Compiling assets

* Setting up database tables

* Running the server
  - 파이썬에서 직접 서버를 돌리지 말고 nginx와 uWSGI를 이용해야 합니다.
  - 안그러면 Judge와 통신이 힘듭니다.
* Setting up uWSGI
  - `uwsgi.ini` 파일 받으시면 됩니다.
* Setting up supervisord
  - `site.conf`, `bridged.conf` 파일 받으시면 됩니다.
* Setting up nginx
  - `nginx.conf` 파일 받으신 후 해당 경로에 받으시면 됩니다.
* Configuration of event server
  - `config.js`에 나와있는 포트들을 통해 채점 상황을 실시간으로 볼 수 있습니다. 하지만 UOSPC 2017에서는 오류로 인해 활용하지 못했습니다.
#### Judge
* Installing the prerequisites
* Configuring the judge
  - 파이썬으로 작성되었기 때문에 운영체제는 딱히 상관없습니다.
  - [Linux Installation - DMOJ Docs](https://dmoj.readthedocs.io/en/latest/judge/linux_installation/) 해당 링크에 나와있는 `config.yml`의 예제가 문법이 잘못 되어있을 수 있습니다.
  - [example configuration file](https://github.com/DMOJ/docs/blob/master/sample_files/judge_conf.yml) 이 링크를 반드시 참고하시기 바랍니다.
  - yaml 문법을 참고해도 좋습니다.
* Problem
  - Problem Format, Problem Examples를 반드시 참고해주세요.
### 2. 기능
* Managing Problems Through the Site Interface
  - Adding a Problem, Editing Test Data, Submitting a Problem
  - 굳이 문서를 읽지 않아도 충분히 사이트를 통해 방법을 습득할 수 있습니다.
* Admin
  - `your.server.url/admin` 으로 접속합니다.
  - Dashboard는 최근 설정을 바꾼 기록이 우측에 뜹니다. 중요한 정보가 뜨지는 않습니다.
  - Problems에서 문제를 추가, 변경, 삭제할 수 있습니다.
  - Submissions에서 제출된 코드들의 채점 현황을 확인할 수 있습니다. 코드를 조회 및 변경도 가능하고, 재채점까지 할 수 있습니다.
  - Contests에서 대회를 추가, 변경, 삭제할 수 있습니다. Problems에서 문제들을 추가한 뒤, Contests에서 대회를 추가할 때 해당하는 문제들을 추가할 수 있습니다. 
  - Users에서 사용자 계정 추가, 변경, 삭제할 수 있습니다.
  - User profiles에서 사용자 인증 및 프로필 변경 가능합니다
  - Navigation Bar에서 페이지 상단 바를 수정할 수 있습니다.
  - Blog Posts에서 공지 같은 글을 게시할 수 있습니다.
  - Comments에서 문제나 대회, 글에 달린 댓글들을 살펴볼 수 있습니다.
  - Flat Pages에서 대회 소개같은 정적 페이지를 생성하고 이를 Navigation Bar에서 보이도록 메뉴를 추가할 수 있습니다.
  - Messages는 안써봐서 잘 모르겠습니다 ㅠㅠ
* 사용자 가입 및 인증
  - 이메일 인증과 reCAPTCHA 인증 기능이 추가되어 있습니다. UOSPC 2017에서는 이메일 서버 오류로 이메일 인증이 불가능했었습니다.
  - 그래서 구글 폼을 이용해서 신청 및 개인정보를 받아 하나씩 계정을 생성했습니다.
  - 중복 가입 및 스팸을 막기 위해서는 학교 메일을 통한 이메일 인증이 필요한 것 같습니다.
