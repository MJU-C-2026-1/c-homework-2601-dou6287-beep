/* 
  파일이름: main.c
  작 성 자: 김도우
  하 는 일: 학생
*/

#include <stdio.h>

int main() {
    // 1. 변수 설계 (5개 이상) 및 다양한 자료형 사용(문자형, 정수형, 실수형)
    char practice_type;       // 연습 종류 (문자형)
    int target_bpm;           // 목표 BPM (정수형)
    int current_bpm;          // 오늘 도달한 최고 BPM (정수형)
    int bpm_remaining;        // 목표까지 남은 BPM (정수형)
    float practice_hours;     // 연습시간(시간 단위) (실수형)
    float achievement_rate;   // 목표 달성률(%)

    // 2. 프로그램 시작 화면 출력
    printf("=== 드럼 연습 기록 및 분석 프로그램 ===\n");

    // 3. 사용자 입력 받기
    printf("오늘의 주된 연습 종류를 알파벳 한 글자로 입력하세요 (R:루디먼트, S:곡, F:프리): ");
    scanf("%c", &practice_type);

    printf("오늘 연습한 총 시간(시간 단위, 예: 1.5)을 입력하세요: ");
    scanf("%f", &practice_hours);

    printf("목표로 하는 템포(BPM)를 입력하세요: ");
    scanf("%d", &target_bpm);

    printf("오늘 도달한 최고 템포(BPM)를 입력하세요: ");
    scanf("%d", &current_bpm);

    //목표 BPM까지 남은 수치 계산 (뻴셈)
    bpm_remaining = target_bpm - current_bpm;

    //목표 달성률 계산 (나눗셈 및 곱셈)
    achievement_rate = ((float)current_bpm / target_bpm) * 100.0;

    //분석 결과 출력
    printf("\n----- 오늘의 연습 분석 결과 -----\n");
    printf("연습 종류:\t\t%c 타입\n", practice_type);
    printf("총 연습 시간:\t\t%.1f 시간\n", practice_hours);
    printf("목표 BPM:\t\t%d\n", target_bpm);
    printf("현재 최고 BPM:\t\t%d\n", current_bpm);
    if(bpm_remaining <= 0)
    {
      printf("목표까지 남은 BPM:\t(목표 초과 달성!)\n");
    }
    else
    {
      printf("목표까지 남은 BPM:\t%d\n", bpm_remaining);
    }
    printf("현재 목표 달성률:\t%.2f%%\n", achievement_rate);
    printf("---------------------------------\n");
    //연습 피드백
    printf("[연습 피드백]\n");
    //다중 조건문 및 관계연산자 및 관계연산자
    if(achievement_rate >= 100.0)
    {
      printf("축하합니다! 오늘의 목표 템포를 완벽하게 달성했습니다.\n");
      //중첩 조건문 및 논리 연산자
      if(practice_hours >= 2.0 && practice_type == 'R')
      {
        printf("2시간 이상의 맹연습과 루디먼트(R) 기초 훈련이 겹쳐 엄청난 성과를 냈군요! 최고입니다.\n");
      }
      else if(practice_hours >= 2.0)
      {
        printf("긴 시간 동안 집중력을 잃지 않고 달성해 낸 훌륭한 결과입니다!\n");
      }
      else
      {
        printf("단기간에 엄청난 집중력을 발휘했군요! 다음엔 지구력을 위해 연습 시간을 늘려보는 것도 좋겠습니다.\n");
      }
    }
    else if(achievement_rate >= 80.0)
    {
      printf("아주 좋습니다! 목표 달성까지 정말 얼마 안 남았어요.\n");
      //중첩 조건문
      if(bpm_remaining <= 10)
      {
        printf("목표 템포까지 고작 %d BPM 남았습니다! 메트로놈을 조금씩만 더 올려보세요.\n", bpm_remaining);
      }
      else
      {
        printf("페이스가 아주 좋습니다. 다음엔 꼭 목표를 넘길 수 있을 거예요!\n");
      }
    }
    else
    {
      printf("아직은 템포를 올리기 위한 워밍업 단계입니다.\n");
      //중첩 조건문
      if(practice_type == 'S')
      {
        printf("곡(S) 연습 중이시군요! 무리해서 템포를 올리기보다는 정확한 박자와 그루브에 집중해 보세요.\n");
      }
      else
      {
        printf("조급해하지 말고 메트로놈과 친해지는 시간을 충분히 가져보세요. 파이팅!\n");
      }
    }
    printf("=================================\n");

    return 0;
}
