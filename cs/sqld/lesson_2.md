### [목차](./readme.md)

### [강의 바로가기](https://www.youtube.com/watch?v=mKCQLJCwZ_8&ab_channel=EPASSKOREA)

###  ?

#### 1. 관계형 데이터베이스 개요
- 개념
    - 관계와 조인 연산을 통해서 합집합, 교집합, 차집합 등을 만들 수 있다.
    - Oracle, MS_SQL, MySQL, Sybase 등..
- 데이터베이스와 데이터베이스 관리 시스템의 차이
    - 데이터베이스는 데이터를 어떤 형태의 자료구조로 사용 하느냐에 따라 나누어진다.
    - 데이터베이스에는 계층형, 네트워크형, 관계형 데이터베이스 등이 있다.
    - 계층형은 트리 자료구조, 네트워크는 오너와 멤버 형태로 데이터를 저장
    - 계층형은 1:N관게를 표현, 네트워크형은 1:N, N:M 관계를 표현
    - 관계형은 릴레이션에 데이터를 저장하고 관리하며 집합연산 및 관계연산을 할 수 있다.
    - 데이터베이스 관리 시스템은 계층, 네트워크, 관계형 데이터베이스 등을 관리하기 위한 소프트웨어를 의미하며 DBMS라고 한다.

- 집합연산
    - 두 개의 릴레이션의 합을 의미하는 합집합
    - 특정 릴레이션에만 존재하며 다른 릴레이션에는 존재 하지 않는 것을 의미하는 차집합
    - 두 릴레이션에 함께 존재하는 것을 의미하는 교집합
    - 각 릴레이션에 존재하는 모든 데이터를 조합하는 곱집합

- 관계연산
    - 선택연산 : 릴레이션에서 특정 조건에 해당하는 행(튜플)만 조회
    - 투영연산 : 릴레이션에서 특정 조건에 맞는 속성만 조회
    - 결합연산 : 여러 릴레이션에서 공토오딘 속성을 통해 새로운 릴레이션을 만듬
    - 나누기연산 : 기준 릴레이션에서 나누는 릴레이션이 가지는 속성과 동일한 값을 가지는 행(튜플)만 추출하여 나누는 릴레이션의 속성을 삭제한 후 중복된 행을 제거

- 테이블과 컬럼
    - 관계형 데이터베이스에서 릴레이션은 곧 테이블
    - 테이블은 행과 컬럼으로 구성되며, 하나의 기본키를 가지고 있다.
    - 컬럼은 어떤 데이터를 저장하기 위한 필드로써 속성이라고도 한다.
    - 외래키는 다른 테이블의 기본키를 참조하는 컬럼이다.

- SQL(Structed Query Language)
    - 관계형 데이터베이스에서 데이터 정의, 조작, 제어를 하기 위해 사용하는 언어
    - SQL은 단순한 스크립트가 아니라 일반적인 개발 언어와 같이 독립된 하나의 개발 언어이다.
    - 관계형 데이터베이스에 대한 전담 접속 용도로 사용되며 독립되어 있다.

- SQL 문장의 종류
    - 데이터 정의어(DDL)
        - CREATE, DROP, RENAME, ALTER, TRUNCATE
        - 테이블이나 컬럼과 같이 데이터 구조를 저으이하는데 사용되는 명령어 
        - 구조를 생성, 변경, 삭제 하는 데이터 구조와 관련된 명령어
    - 데이터 조작어(DML)
        - SELECT, INSERT, DELETE, UPDATE
        - 데이터베이스내 데이터를 조회 및 검색하기 위한 명령어
        - 데이터의 추가, 삭제, 수정 하기 위한 명령어
    - 데이터 제어어(DCL)
        - GRANT, REVOKE
        - 데이터베이스에 접근하고 객체들을 사용하도록 권한을 부여하거나 회수하는 명려엉
    - 트랜잭션 제어어(TCL)
        - COMMIT, ROLLBACK, SAVEPOINT
        - 트랜잭션 별로 제어하는 명령어

- 트랜잭션(Transaction)
    - 개념
        - 트랜잭션은 데이터베이스의 작업을 처리하는 단위
    - 특징
        - 원자성(Atomicity)
            - 트랜잭션은 데이터베이스내서 실행되는 연산의 전부가 실행되거나 실행되지 않아야 한다.
            - 트랜잭션이 완전히 끝나지 않았을 경우에는 실행되기 전의 상태와 같아야 한다.
        - 일관성(Consistency)
            - 트랜잭션 실행 결과로 데이터베이스의 상태가 모순되지 않아야 한다.
            - 트랜잭션 실행 후에도 일관성이 유지되어야 한다.
        - 고립성(Isolation)
            - 트랜잭션 실행 중에 생성하는 연산의 중간결과는 다른 트랜잭션이 접근할 수 없다.
            - 부분적인 실행 결과를 다른 트랜잭션이 볼 수 없다.
        - 영속성(Durability)
            - 트랜잭션이 그 실행을 성공적으로 완료하면 그 결과는 영구적 보장이 되어야 한다.

- SQL 실행 순서
    - 파싱(Parsing)
        - SQL 문법을 확인하고 구문 분석을 한다.
        - 구문 분석한 SQL을 Libary Cache에 저장한다.
    - 실행(Execution)
        - 옵티마이저가 생성한  실행 계획에 따라 SQL을 실행한다.
    - 인출(Fetch)
        - 데이터를 읽어 전송한다.


#### 2. SELECT
- 개념
    - 테이블 내 저장된 데이터를 죄회하기 위해 사용
    - 특정 행 또는 특정 컬럼을 조회 할 수 있음.

- SELECT 문법
    ```
    SELECT 컬럼명
    FROM 테이블명
    WHERE 조건
    ORDER BY asc;
    ```

- SELECT 컬럼 지정방법

- ORDER BY
    - 오름차순(default) / 내림차순
    - 정렬은 가장 나중에
    - 정렬은 메모리를 많이 사용한다.
    - 인덱스를 사용하여 정렬과정을 회피 할 수 있다.
        ```
        SELECT * /* + INDEX_DESC(A) */
        FROM user;
        ```

- DISTINCT
    - 개념 : SELECT절의 컬럼 앞에 위치하며 중복을 제거한 결과를 출력

- Alias
    - 테이블명 또는 컬럼명의 길이가 길거나 복잡할 때, 함수를 사용 했을 떄 사용
        ```
        SELECT user_id as "ID", user_pwd `pwd`
        FROM users;
        ```

- WHERE
    - =, <, >, !=, <>, Not, Like, Between A and B, in (), is not null, is null

- DUAL 테이블
    - 개념 : 오라클에서 임시로 사용 할 수 있는 더미 테이블
    - 간단하게 함수를 테스트 하거나 데이터를 테스트 할 때 사용 할 수 있다.
        ```
        SELECT 1, 2, 3
        FROM dual;
        ```

#### 3. 함수
- NULL 정의
    - 데이터의 정의가 없는 것
    - 알 수 없는 값을 의미
    - NULL을 이용하여 숫자나 날짜 연산을 한다면 결과는 무조건 NULL

- NULL 조회
    - NULL값을 조회 할 때는 조건절에 is null, is not null을 사용한다.

- 문자함수
    - lower/upper(문자열)
    - length(문자열)
    - substr(문자열, 시작위치, 길이)
    - instr(문자열, A) : A의 위치
    - lpad,rpad(문자열, 자리수, A) : 남은 자리 A로 채움
    - trim/ltrim/rtrim(문자열) : 공백 제거 
    - replace(문자열, 대체할, 대체될)

- 숫자함수
    - round(숫자, 소수점 n자리까지)
    - truncate(숫자, ~까지) : 버림
    - ceil/floor(슷자) : 위, 아래로 가장 가까운 정수 출력
    - power(숫자, 몇제곱)

- 날짜함수
    - sysdate, systimestamp
    - add_months(날짜, m) : 날짜 + m월
    - next_day(날짜, '월요일') : 다음 월요일
    - last_day
    - to_char(날짜 + 1/24/60/60) : 1초 뒤

#### 4. GROUP BY
- Group by
    - 집합(테이블) 내에서 하나 혹은 여러 행을 그룹화하여 합계, 평균, max, min 등 집계 함수를 이용하여 계산할 수 있는 기능
    - Having 절을 이용하여 group by 된 상태에서 조건을 추가 할 수 있다.

- Having
    - group by와 같이 쓰는 조건절

- 집계 함수
    - count
    - sum/avg
    - min/max

#### 5. 분기문
- NVL
    - NVL은 null인 값을 제거하기 위한 일반 함수
    - null대신 특정 숫자나 다른 값을 출력 할 수 있다.
    - NVL(값, 'null일 떄 출력 값')

- NVL2
    - NVL2는 NVL에 비해 파라미터가 하나 더 있다.
    - NVL(값, 'null이 아닐 떄 출력 값', 'null일 떄 출력 값')

- decode
    - 한 컬럼에 여러가지 조건을 적용 하여 출력 할 떄 사용한다.
    - decode(값, 조건1, 결과1, 조건2, 결과2, ...)

- Case when
    - 여러가지 컬럼 및 조건으로 다양한 조건을 적용해야 할 때 사용한다.
    - 하나의 컬럼 값으로 비교 할 떄와 여러 컬럼으로 비교 할 때와 문법을 두가지로 나눠 사용할 수 있다.
    - 나열된 순으로 조건 비교를 한다.
    - case when then else then

#### 6. rownum, rowid, with문

- rownum
    - Oracle에서 출력 rows를 설정 하는 기능
    - Mssql에서는 top() 기능으로 대체하여 사용할 수 있다.

- rowid
    - Oracle에서 row가 생성 될 떄 부여하는 row의 고유 id
    - Rowid로 조건을 입력 할 수도 있다.
    - 데이터객체번호, 상대적파일번호, 블록번호, 행번호의 조합이다.

- with문
    - 일종의 임시적인 view 테이블
    - 특정 sql 블록의 재사용을 위해 사용
    - SQL 실행 속도에 유리하게 작용할 수 있다.
    - 여러 번 사용될수록 유리하다.
    - 하나의 SQL 문에서 여러 개의 with문을 사용 할 수 있다.

#### 7. DDL
- DDL
    - 테이블 또는 데이터베이스내 객체 등의 구조를 정의하는 명령
    - 구조를 생성하거나 변경 또는 삭제 할 떄 사용하는 명령

- Create table
    - 테이블을 생성하는 DDL문
    - Primary key, foriegn key, check 등 제약조건 정의 가능
    - 컬럼 및 테이터 타입 정의

- Alter
    - 테이블이나 컬럼의 구조를 변경하는 명령
    - 제약조건을 추가 하거나 삭제 하는 명령
    - alter table ~ rename column ~ to ~
    - alter table ~ modify ~ ~
    - alter table ~ drop ~
    - alter table ~ add constaint ~ ~ referencces ~

- Drop
    - 테이블이나 특정 객체를 삭제하는 명령
    - 테이블내 데이터와 구조를 삭제한다.
    - Cascade constarint 옵션은 종속된 제약조건도 모두 삭제함

- Truncate
    - 테이블 구조는 남겨두고 내부의 데이터, 행만 삭제하는 명령어.
    - 테이블이 차지하던 저장공간을 반납한다.

- View
    - 뷰는 실제 데이터를 가지고 있지 않음.
    - select sql만 가지고 있다고 생각하면 됨
    - 참조된 테이블이 변경되면 뷰의 결과도 변경 됨
    - create view ~ as \n select ~ from ~ where ~;
    - 장점
        - 보안에 적합하다.
        - 단순하게 불러 올 수 있다.
        - 하나의 테이블로 여러 결과를 가진 뷰를 생성 할 수 있다.
    - 단점
        - 삽입, 갱신 등 연산이 제한적이다.
        - 데이터 구조를 쉽게 변경 할 수 없다.
        - 인덱싱 하기 어렵다.

#### 8. DML

- DML
    - 데이터베이스내 데이터를 조회 하거나 입력, 수정 삭제 하는 명령

- SELECT
    - 테이블내 데이터를 주어진 조건에 맞게 조회 하는 명령어
    - select ~ from ~ ;

- INSERT
    - 데이터를 입력 및 저장 하는 명령어
    - insert into ~(~) VALUES(~), (~);

- UPDATE
    - 데이터를 수정 하는 명령어
    - update ~ set ~ = ~ where ~;

- DELETE
    - 행, ROW를 삭제 하는 명령어
    - delete from ~ where ~ ;

#### 9. DCL

- DCL(Data Control Language)
    - 데이터 베이스 내 유저에 권한을 부여 하거나 회수 하는 명령어

- GRANT
    - 유저에게 각종 오브젝트 권한을 부여할 수 있는 명령어
    - 시스템 권한으로는 DBA, CREATE SESSION, CREATE USER, SYSDBA등이 있따.
    - 부여할 수 있는 오브젝트 권한의 종류는 다음과 같다.
        - ALTER
        - DELETE
        - ALL
        - INDEX
        - INSERT
        - REFETENCED
        - SELECT
        - UPDATE
    - CREATE USER ~ IDENTIFIED BY ~ \n GRANT ~ TO ~; 
- ROLE
    - 권한과 유저사이에 존재하는 개념으로, 다양한 권한을 역할에 따라 유저에게 부여할 때 사용할 수 있다.
    - 특정 ROLE은 여러 권한을 받아 놓고, 특정 유저에게 여러 권한들을 가진 ROLE을 부여함으로 간단하게 권할을 관리할 수 있다.
    - CREATE ROLE ~ \n GRANT ~ TO ~ \n GRANT ~ TO ~;

- TCL(Transaction COntrol Language)
    - 트랜잭션을 관리하는 명령어
    - 밀접히 관련되어 분리 할 수 없는 한 개 이상의 데이터베이스 조작
    - 하나의 트랜잭션은 하나 이상의 SQL 문장을 가지고 있다.
    - 원자성, 일관성, 고립성, 영속성

- Transaction
    - COMMIT
    - ROLLBACK TO ~
    - SAVEPOINT ~

### 2장 SQL 활용

#### 1. 표준조인

- 조인(join)
    - 두개 이상의 테이블을 결합하여 데이터를 출력하는 명령어
    - 관계형 데이터베이스의 핵심적인 기능
    - PK와 FK의 값을 기반으로 join이 성립 된다.
    - INNER JOIN : 동일한 데이터 값을 기준으로 실행
    - NATURAL JOIN : 양 테이블 간 동일한 컬럼영을 가지고 자동으로 매칭
    - CROSS JOIN : JOIN하는 테이블간 조인 조건이 없을 떄 실행
    - OUTER JOIN : 기준이 되는 테이블은 다른 쪽에 값이 없어도 실행되어 출력

- CROSS JOIN
    - 두 개의 테이블 간에 매칭되는 모든 데이터 조합을 출력한다.
    - 카티션곱(CARTESIAN PRODUCT)과 동의어
    - 조건을 따로 정의하지 않는다.
    ```
    SELECT *
    FROM user, board;
    SELECT *
    FROM user CROSS JOIN board;
    ```

- INNER JOIN
    - 두개의 테이블 간에 매칭되는 모든 데이터 조합 중 특정 컬럼끼리 값이 같은 것만 출력
    - INNER 생략 가능
    ```
    SELECT *
    FROM user u INNER JOIN board b ON m.id = b.id;
    ```

- NATURAL JOIN
    - 두 테이블 간에 동일한 이름을 갖는 모든 컬럼들에 대해 자동으로 EQUAL JOIN을 실행

- OUTER JOIN
    - 기준이 되는 한쪽은 매칭되는 값이 없어도 출력
    - 동일한 값이 없다면 한쪽은 NULL이 출력

- ON절
    - JOIN 조건에 사용

- USING절
    - 두 테이블에 존재하는 공통된 컬럼명을 사용
    - 데이터 유형도 동일
    ```
    SELECT *
    FROM user u JOIN board b
    USING (id);
    ```

- 데이터 증가
    - 조인을 잘못하면 데이터가 많아진다.
    - 중보고딘 데이터가 있을 때 JOIN은 신중하게 해야 한다.


#### 2. 서브쿼리

- 서브쿼리(Sub Query)
    - 하나의 SQL에 포함되어 있는 또 다른 SQL을 지칭하는 말
    - 서브쿼리는 대부분의 SQL절에서 사용이 가능하다.
        - select, from, where, having, order ny, set 절 등..
    - 서브쿼리는 시작과 끝을 괄호로 감싸서 표현
    - 서브쿼리는 사용되는 위치에 따라 단일행으로 출력되거나 복수형으로 출력

    - 단일행 서브쿼리 : =, <, >, <> 사용 가능
    - 다중행 서브쿼리 : IN, ALL, ANY, EXISTS 사용 가능

    - 스칼라 서브쿼리 : SELECT 절
    - 인라인 뷰 : FROM 절
    - 중첩 서브쿼리, 서브쿼리 : WHERE 절

- 스칼라 서브쿼리
    - SELECT 절에 사용
    - 성능에 매우 불리

- 인라인뷰
    - SQL의 핵심?
    - FROM절에 사용되는 서브쿼리
    - 동적 뷰

- EXSITS, NOT EXSITS
    - 서브쿼리의 결과가 존재한다면 메인쿼리의 결과가 출력되는 문법
    - EXSITES는 다른 방법으로 구현이 가능하다.
    - ON절 사용이 안된다.
    ```
    SELECT *
    FROM user u
    WHERE EXISTS (SELECT 1
                  FROM board b
                  WHERE u.id = b.id);
    ```

#### 3. 다양한 조인과 집합연산자

- 비등가조인
    - 조인을 할 때 꼭 등가 조인을 하는 건 아니다.
    - 특정 범위나 같지 않다는 조건으로도 조인을 할 수 있다.
    - on a between b and c 등

- 집합연산자
    - 조인은 두개의 테이블을 하나로 만드는데, 좌우로 붙이는 개념
    - 집합연산자는 ROW 단위로, 데이터를 위아래로 붙이는 개념
    - 두개 이상의 SELECT 결과를 하나로 만들어준다.
    - SELECT절의 컬럼수가 같아야 하고, 데이터타입의 호환이 되어야 한다.

- JOIN ... 중복


#### 4. 계층형 SQL

- 계층형 SQL
    - 한 테이블안에 계층적인 데이터 구조를 가진 테이블에서 쉽게 데이터를 출력하기 위한 SQL 문법
    ```
    select 컬럼명
    from 테이블
    where 조건절
    start with 시작조건
    connect by [nocycle] prior 관계방향
    order [siblings] by 정렬조건
    ```

- 계층형 전용 컬럼 및 함수
    - LEVEL : ROOT 부터 한단계씩 내려가면서 증가하는 번호
    - CONNECT_BY_ISLEAF : 각 전개별 최하위 리프에 1, 아니면 0
    - CONNECT_BY_ISCYCLE : 내부적인 값 오류 등으로 자식노드가 다시 내 부모노드가 되는 경우 1을 출력
    - SYS_CONNECT_BY_PATH : ROOT로 부터 각 ROW까지 전개된 데이터 경로를 출력
    - CONNECT_BY_ROOT : 각 전개한 데이터의 루트 데이터를 출력

- 계층형 전용 컬럼 및 함수
    - ROOT 와 LEAF
    - 역방향 전개
    - WHERE절 사용
    - ORDER SINLINGS BY

#### 5. 그룹함수

- 그룹 함수
    - 테이블내 데이터들을 각 컬럼 별로 그룹화 하여 그롭별 결과를 출력하는 함수
    - UNION, UNION ALL으로 대체 가능

- ROLLUP
    - 해당 컬럼의 소개 및 총계를 출력
    - 계층 구조이기에 기준 컬럼수가 2개 이상일 때 순서에 따라 출력이 달라진다.

- GROUPING
    - 해당 컬럼에서 소계 여부를 확인 할 수 있는 함수
    - 이 결과를 정렬에 활용 할 수 있다.
    - Having 절에 사용 가능하다


- GROUPING SETS
    - 집계 대상 컬럼에 대한 소계를 구할 수 있는 그룹 함수
    - 기준 컬럼의 순서와 결과는 상관 없음

- CUBE
    - 결합 가능한 모든 값에 대한 다차원 집계를 출력
    - 기준 컬럼의 순서와 결과는 상관 없음
    - 다른 그룹 함수들 보다 성능상 불리함

- rollup
    - 기준 컬럼이 1개 일 때 cube와 같음
    - 기준 컬럼 순서에 따라 결과 다름
- grouping sets
    - 기준 컬럼 순서와 결과는 무관
- cube
    - 기준 컬럼이 1개일 떄 rollup과 같음
    - 기준 컬럼의 순서와 결과는 무관


#### 6. 윈도우 함수

- 윈도우 함수
    - 데이터를 분석하거나 통계적인 계산을 하는 함수로 주로 사용 된다.
    - 함수 자체를 중첩하여 사용 할 수 없다.
    - 복잡하게 구해야 하는 로직을 쉽게 처리 할 수 있게 한다.

    - 순서, 순위 : rank, dense_rank, row_number
    - 집계, 계산 : sum, avg, count, max, min
    - rows, 위치 : rirst_value, last_value, lag, lead
    - 백분율, 비율 : cume_dist, ratio_to_report, percent_rank, ntile

- FIRST VALUE
    - 특정 기준값에 따른 컬럼의 값을 출력

- LAG
    - 특정 기준값의 순서에 따라서 이전 값이나 이후 값을 출력 할 수 있음

- PERCENT_RANK
    - 기준 파티션 내 순서 별 백분율을 계산하여 0~1 사이 값으로 출력

- NTILE
    - 파라미터 값으로 등분하여 어느 구간에 들어가는지 출력

- ROWS 함수
    - 특정 값을 기준으로 데이터를 줄 세운 뒤 row를 기준으로 연산하여 출력


### 3장 SQL 최적화 기본 원리

#### 1. 옵티마이저와 실행계획

- 옵티마이저
    - DBMS의 핵심 엔진으로써 SQL을 실행할 떄 가장 최적의 경로를 찾아서 선택해 주는 것

- SQL 최적화 과정
    - SQL Parsing
        - SQL 문장을 이루는 개별 요소 분석
    - Optimization
        - 일반적인 쿼리로 변환, 비용 계산, 실행계획 후보 선정
    - Row Source Generation
        - 실행계획을 실제 실행하는 코드로 포맷
    - Execution
        - SQL 실행

- 옵티마이저 유형
    - 규칙기반 옵티마이저는 규칙에 대한 우선순위로 실행계획을 생성한다.
    - 비용기반 옵티마이저는 예상 소요시간, 자원 사용량을 계산하여 실행 계획을 수립하는 방식

- 실행계획
    - SQL을 어떤 경로로 실행할 것 인지에 대한 계획
    - 동일한 SQL도 실행 계획에 따라 성능이 달라진다.

    - 액세스 기법 : 테이블내 데이터를 읽는 방법(INDEX SCAN, FULL TABLE SCAN)
    - 조인 순서 : SQL내 조인을 수행 할 떄 참조하는 테이블의 순서
    - 조인 기법 : 조인시 조인을 수행하는 방법(NESTED LOOP JOIN, SORT MERGE JOIN, HASH JOIN)
    - 최적화 정보 : 단계별로 예상되는 비용(성능, 시간)


#### 2. 인덱스 기본

- 인덱스
    - 데이터를 SCAN 하는 속도를 향상 시키기 위해서 사용 하는 기능
    - 관계형 데이트베이스에서는 B-트리 인덱스를 가장 많이 사용한다.
    - 하나의 테이블에 여러 개 생성 가능하다.
    - 하나의 인덱스는 여러 컬럼을 포함 할 수 있따.
    - 오름차순, 내림차순으로 인덱스의 정렬 순서를 설정 할 수 있다.
    - Unique INdex에는 NULL값이 포함될 수 있다.

    - 장점
        - 검색속도 향상
        - 시스템의 부하를 줄여줌
    - 단점
        - 추가 저장 공간 필요
        - 생성 시간 필요
        - INSERT, UPDATE, DELETE 작업 시 부하 발생

    - Full Table Sccan
        - 전체 테이블을 모두 읽어 가며 조건에 맞는 데이터를 찾는 방식
    - Index Unique Scan
        - 하나의 값을 찾으면 scan 종료 등가조건(=)만 가능
    - Index Range Scan
        - 특정 범위를 조회한다. 데이터가 적으면 FTS이 될 수 있다.
    - Index Range Scan Descending
        - 인덱스를 역순으로 읽는다. Max값을 찾을 떄 주로 쓰인다.