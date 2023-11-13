### [목차](./readme.md)

### [강의 바로가기](https://www.youtube.com/watch?v=gmMaH5mMJ9M&ab_channel=EPASSKOREA)

### 1장 데이터 모델링의 이해

#### 1. 데이터 모델링

- 정의 : 현실의 정보를 데이터베이스에서 표현하기 위한 추상화 과정
- 특징
  - 추상화(Abstraction) : 현실 세계를 일정한 양식에 맞게 간략하게 표현한다.
  - 단순화(Simplification) : 누구나 이해하기 쉽도록 약속된 규약에 의한 제한된 표기법 또는 언어를 이요하여 표현한다.
  - 명확화(Clarity) : 명확하게 의미가 한 가지로 해석되어야 함으로 애매모호함을 제거하고 정확하게 현상을 기술한다.
- 단계
  - 개념적 모델링
    - 추상화 수준이 가장 높다.
    - 업무 측면의 모델링
    - 전사적이고 포괄적인 모델링
    - 핵심 엔터티 도출
    - ERD 작성
  - 논리적 모델링
    - 특정 데이터베이스 모델에 종속된다.
    - 세부속성, 식별자, 관계 등을 정확하게 표현
    - 데이터 정규화 완료
    - 재사용성이 높음
  - 물리적 모델링
    - 물리적인 성능과 데이터 저장을 고려한 설계
    - 가장 구체적인 데이터 모델랑
    - 추상화 수준이 가장 낮은 단계
    - 성능, 보안, 가용성을 고려한 데이터베이스 모델링 진행
- 3가지 관점
  - 데이터 관점
    - 데이터와 업무 간의 어떤 관련이 있는지, 데이터와 데이터 사이의 관계가 무엇인지에 따라 모델링
    - 구조분석, 정적분석
  - 프로세스 관점
    - 실제 하는 업무에 따라 무엇을 어떻게 하는지 모델링
    - 시나리오 분석, 도메인 분석, 동적 분석
  - 데이터와 프로세스의 상관 관점
    - 업무의 처리와 데이터 간의 서로 어떤 영향을 주고 받는지를 모델링
      - CRUD
- ERD
  - 표기법 : Chen, IE/Crow's Foot, Barker, URL
  - 작성 순서
    - 엔티티 도출
    - 엔티티 배치
    - 엔티티 관계 설정
    - 관계명 기술
    - 관계 참여도 기술
    - 관계 필수 여부 기술
- 3단계 구조 스키마
  - 데이터베이스의 독립성을 위해서 3단계 구조 스키마가 존재.
  - 데이터의 독립성 확보를 통해서 데이터 복잡도 감소, 데이터 중복 제고, 사용자 요구사항 변경에 따른 대응력 향상, 관리 및 유지보수 비용 절감 등의 장점
  - 사용자(외부 스키마)
    - 데이터베이스의 개별 사용자 관점의 이해와 표현
    - 응용프로그램이 접근하는 데이터베이스
    - 여러 개의 외부 스키마 존재
  - 설계자(내부 스키마)
    - 데이터베이스 관리자의 관점으로 규칙과 구조 표현
    - 데이터베이스의 전체적인 논리구조
    - 일반적으로 스키마는 개념 스키마를 지칭
  - 개발자(개념 스키마)
    - 데이터베이스 시스템의 설계자 관점으로 저장 장치 관점의 이해 및 표현
    - 데이터가 실제로 데이터베이스에 물리적으로 어떻게 저장 되는지 확인

#### 2. 엔터티

- 개념 : 데이터의 집합, 저장되며 관리되는 데이터(≒테이블)
- 유형과 무령에 따른 분류
  - 유형 엔터티 : 물리적이며 안정적이며, 지속적인 엔터티(교수)
  - 개념 엔터티 : 물리적이진 않지만 개념적으로 존재하며 정보로 구분되는 엔터티(강의)
  - 사건 엔터티 : 비즈니스 프로세스에 따라 발생되는 엔터티, 데이터가 많다(수업)
- 발생 시점에 따른 엔터티 분류
  - 기본 엔터티 : 키 엔터티, 독립적으로 생성 및 관리 된다
  - 중심 엔터티 : 기본 엔터티로 부터 발행되는 행위 엔터티를 생성하는 중간 엔터티
  - 행위 엔터티 : 상위에 있는 2개 이상의 엔터티로 부터 발생되는 엔터티

#### 3. 속성

- 개념 : 엔터티가 가지는 항목
- 특징
  - 속성은 더 이상 분리 되지 않는다.
  - 인스턴트의 구성 요소로 최소의 데이터 단위이다.
  - 속성은 하나의 값만 가진다.
  - 주식별자에게 함수적으로 종속된다. 기본키에 따라 속성의 값도 변경될 수 있다.
- 특성에 따른 속성의 종류
  - 기본 속성 : 비즈니스 프로세스에서 도출한 본래의 속성(이름)
  - 설계 속성 : 데이터 모델링 과정에서 발생되는 속성(상품코드)
  - 파생 속성 : 다른 속성에 의해 만들어지는 속성(합계)

#### 4. 관계

- 개념 : 엔터티간 논리적인 연관성
- 관계의 분류
  - 존재에 의한 관계 : 부서 - 사원
  - 행위에 의한 관계 : 고객 - 주문명
- 관계의 표기법
  - 관계명
    - 관계에 엔터티가 참여하는 형태를 정의
    - 각 두개의 관계명을 가진다.
    - 관계명은 능동적 또는 수동적으로 명명
    - 애매한 동사를 피하고 현재형으로 표현
  - 관계차수 : 관계있는 엔터티간 참여하는 수를 의미
    - 1:1, 1:N, N:M
  - 관계선택사양 : 엔터티가 관계에 있어 항상 참여하는지, 선택적 참여하는지
    - 필수관계, 선택관계

#### 5. 식별자

- 개념 : 엔터티를 대표하는 속성
- 특징
  - 하나의 엔터티는 반드시 하나의 유일한 식별자를 가지고 있어야 한다.
  - 엔터티내 각 인스턴스를 유일하게 구분할 수 있는 구분자
  - 다른 엔터티와 관계를 연결하는 식별자
  - 유일성, 희소성, 불변성, 존재성을 만족
- 주식별자의 특징
  - 최소성 : 주식별자를 구성하는 속성의 수는 유일성을 만족하는 최소의 수가 되어야 한다.
  - 존재성 : 주식별자가 지정 되면 반드시 값이 존재 해야 한다.
  - 유일성 : 주식별자에 의해 엔터티 내에 모든 인스턴스들을 유일하게 구분 해야 한다.
  - 불변성 : 주식별자가 한번 특정 엔터티에 저장되면 그 식별자의 값은 변하지 않아야 한다.
- 키의 종류
  - 기본키(Primary Key) : 후보키 중에서 엔터티를 대표할 수 있는 키
  - 후보키(Candidate Key) : 유일성과 최소성을 만족하는 키
  - 슈퍼키(Super Key) : 유일성은 만족하지만 최소성을 만족하지 않는 키
  - 대체키(Alternate Key) : 여러 개의 후보키 중에서 기본키를 선정하고 남은 키
  - 외래키(Foreign Key) : 타 테이블의 기본키 필드를 가리키는 것으로 참조무결성을 확인하기 위해 사용되는 키
- 식별자 분류
  - 내부식별자 : 엔터티 내부에서 스스로 생성되는 식별자
  - 외부식별자 : 다른 엔터티와 관계로 인하여 만들어지는 식별자
  - 단일식별자 : 하나의 속성으로 구성
  - 복합식별자 : 다수의 속성으로 구성
  - 본질식별자 : 비즈니스 프로세스에서 만들어지는 식별자
  - 인조식별자 : 인위적으로 만들어지는 식별자
- 주식별자 도출방법
  - 해당 업무 및 데이터에서 주로 사용되는 속성을 주식별자로 지정한다.
  - 이름이나 명명된 호칭, 길이가 일정하지 않은 내용 들은 주식별자로 지정하지 않는다.
  - 복합키를 구성할 때 너무 많은 속성이 포함되지 않도록 주의한다.
- 식별자 관계와 비식별자 관계
  - 강한 관계 : 부모 엔터티와 주식별자가 자식 엔터티의 주식별자로 상속되는 경우
  - 약한 관계 : 부모 엔터티와 주식별자가 자식 엔터티의 일반 속성으로 상속되는 경우

### 2장 데이터 모델과 성능

#### 1. 성능 데이터 모델링의 개요

- 개념 : 분석 및 설계 단계부터 데이터베이스 성능을 고려한 모델링을 수행하는 기법
- 수행 절차
  - 데이터 모델링을 할 때 정규화를 정확하게 수행
  - 데이터베이스 용량을 현재와 예상 증가량을 고려하여 조사
  - 데이터베이스에 발생되는 트랜잭션의 유형을 파악
  - 용량과 트랜잭션의 유형에 따라 반정규화를 수행
  - 여러모델의 조정, PK/FK 조정, 슈퍼타입/서브타입 조정 등을 수행한다.
  - 성능관점에서 데이터 모델을 검증한다.

#### 2. 정규화의 성능

- 개념
  - 데이터의 일관성, 최소한의 중복, 최대한의 데이터 유연성을 위한 방법.
  - 데이터를 분해하는 과정
  - 데이터의 중복을 제거
  - 데이터 모델의 독립성 확보
  - 데이터 이상현상(Abnomality)을 줄이기 위한 설계 기법
  - 엔터티를 상세화하는 과정이며 논리 데이터 모델링 수행 시점에서 고려
- 이상현상(Abnomality)
  - 삽입이상 : 행 삽입 시 지정되지 않은 속성 값이 NULL을 가지는 경우
  - 갱신이상 : 데이터 갱신 시 일부분의 데이터만 갱신되어 일관성 유지가 안되는 경우
  - 삭제이상 : 행 삭제 시 원하지 않는 연쇄 삭제가 발생하는 현상
- 정규화의 단계
  - 제1정규화
    - 테이블 내 속성의 원자성을 확보하는 단계
    - 기본키를 설정
  - 제2정규화
    - 기본키가 2개 이상의 속성으로 이루어진 경우 부분 함수 종속성을 제거
  - 제3정규화
    - 기본키를 제외한 컬럼 간 종속성을 제거
    - 이행 함수 종속성을 제거
  - BCNF(Boyce-Codd Normal Form)
    - 기본키를 제외하고 후보키가 있는 경우, 후보키가 기본키를 종속 시키면 분해
    - 결정자 함수 종속성을 제거하는 단계
    - 강한 제3정규화
  - 제4정규화
    - 여러 컬럼들이 하나의 컬럼을 종속 시키는 경우 분해하여 다중값 종속성을 제거
  - 제5정규화
    - 조인에 의한 종속성이 발생하는 경우 분해
- 주의사항
  - 모든 정규화는 이전 정규화를 만족해야 한다.
  - 정규화시 이상현상은 제거 되지만 테이블의 분해로 데이터 조인의 발생이 많아지고, 이는 조회 성능 저하로 이어질 수 있다.(I/O증가 및 조인 연산 증가)
  - 단일 테이블 조회시엔 데이터 중복이 제거되어 조회 성능이 향상 될 여지가 있다.

#### 3. 반정규화의 성능

- 개념
  - 데이터베이스 성능 향상을 위해 데이터 중복을 허용하고 조인을 줄이는 방법
  - 시스템의 성능 향상 및 개발 운영의 단순화를 위해 정규화된 데이터 모델을 중복, 통합, 분리하는 데이터 모델링 기법
  - 조회속도를 향상 시킬 수 있지만 데이터 모델의 유연성은 낮아진다.
  - 비정규화는 정규화를 수행하지 않음 / 반정규화는 역정규화
- 수행해야 하는 이유
  - 정규화를 잘하면 종속성 활용성은 향상되지만 수행 속도가 느려지는 경우
  - 다량의 범위를 자주 처리해야 하는 경우
  - 특정 범위의 데이터만 자주 처리 하는 경우
  - 요약/집계 정보를 자주 사용 하는 경우
- 절차
  - 대상 조사 및 검토
    - 데이터 처리 범위, 통계썽 등을 확인 후 반정규화를 수행
    - 대량의 범위처리 및 빈도수, 통계성 프로세스, 테이블 조인 수
  - 다른 방법 검토
    - 클러스터링, 뷰, 인덱스, 응용 프로그램, 파티셔닝 등 다른 방법으로 해결 할 수 있는지 확인
  - 반정규화 수행
    - 테이블, 속성, 관계 등을 반정규화한다.
- 기법
  - 테이블 병합, 분할, 추가
  - 중복 컬럼 추가 등...
  - 중복 관계 추가

#### 4. 데이터베이스 구조

- 개념
  - 중앙집정형 데이터베이스: 현대의 물리적 시스템에 여러 명의 사용자가 접속해서 사용하는 데이터베이스
  - 분산 데이터베이스 : 물리적으로 떨어져 있지만 네트워크로 연결된 단일 데이터베이스 이미지를 보여주고 분산된 작업을 하는 데이터베이스
- 분산 데이터베이스의 투명성
  - 분할 투명성
    - 고객은 하나의 논리적 관계가 여러 단편으로 분할 되어 각 단편의 사본이 여러 시스템에 저장 되어 있음을 알 필요는 없다.
  - 위치 투명성
    - 고객이 사용하는 데이터베이스의 위치를 알릴 필요가 없다.
    - 어느 위치에서 접근 하더라도 동일한 명령으로 접근 할 수 있어야 한다.
  - 지역 사상 투명성
    - 지역 DBMS와 물적 데이터베이스 사이의 사상이 보장됨에 따라 각 지역 시스템 이름과 무관한 이름을 사용 할 수 있다.
  - 중복 투명성
    - 데이터베이스 객체가 여러 시스템에 중복되어 존재함에도 고객과는 무관하게 데이터 일관성이 유지되어야 한다.
  - 장애 투명성
    - 데이터베이스가 분산되어 있는 각 지역의 시스템이나 통신망에 이상이 발생해도 데이터의 무결성은 보장 되어야 한다.
  - 병행 투명성
    - 여러 고객의 응용프로그램이 동시에 분산 데이터베이스에 대한 트랜잭션을 수행하는 경우에도 결과에 이상이 없어야 한다.
  - 분산 데이터베이스 설계 방식
    - 상향식 설계 방식 : 지역 스키마 작성 후 향후 전역 스키마를 작성
    - 하향식 설계 방식 : 전역 스키마 작성 후 해당 지역 사상 스키마를 작성
- 장점
  - 데이터베이스 신뢰성과 기용성이 높다
  - 분산 데이터베이스가 병렬 처리를 수행하기때문에 빠르다
  - 분산 데이터베이스를 추가하여 시스템 용량 확장이 쉽다.
- 단점
  - 데이터베이스가 여러 네트워크를 통해서 분리되어 있기때문에 관리 및 통제가 어렵다.
  - 보안관리가 어렵다.
  - 데이터 무결성 관리가 어렵다.
  - 데이터베이스 설계가 복잡하다.