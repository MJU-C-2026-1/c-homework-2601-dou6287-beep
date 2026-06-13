/* 
  파일이름: main.c
  작 성 자: 김도우
  하 는 일: 학생
*/

#include <stdio.h>

#define MAX_DAYS 5
  
    char practice_type[MAX_DAYS];       // 연습 종류
    float practice_hours[MAX_DAYS];     // 연습시간
    int target_bpm[MAX_DAYS];           // 목표 BPM
    int current_bpm[MAX_DAYS];          // 현재 최고 BPM
    int entry_count = 0;                // 현재까지 입력된 데이터의 개수 추적

// 1. 입력 함수
void input_practice_data()
{
  if(entry_count >= MAX_DAYS)
  {
    printf("\n>> 데이터 저장 공간이 가득 찼습니다 (최대 %d일).\n", MAX_DAYS);
    return;
  }
    printf("\n--- [1] 연습 기록 입력 (Day %d) ---\n", entry_count + 1);
    printf("오늘의 주된 연습 종류 (R:루디먼트, S:곡, F:프리): ");
    scanf(" %c", &practice_type[entry_count]);
    printf("총 연습 시간(시간 단위, 예: 1.5): ");
    scanf("%f", &practice_hours[entry_count]);
    printf("목표 템포(BPM): ");
    scanf("%d", &target_bpm[entry_count]);
    printf("오늘 도달한 최고 템포(BPM): ");
    scanf("%d", &current_bpm[entry_count]);

    entry_count++;
    printf(">> 데이터가 성공적으로 저장되었습니다!\n");
}

// 2. 조회 함수
void view_practice_data()
{
  if(entry_count == 0)
  {
    printf("\n>> 입력된 데이터가 없습니다. 먼저 [1. 입력]을 진행해주세요.\n");
    return;
  }
    printf("\n--- [2] 전체 연습 데이터 조회 ---\n");
    for(int i=0; i<entry_count; i++)
    {
      printf("[Day %d] 연습 종류: %c | 연습 시간: %.1f시간 | 목표 BPM: %d | 최고 BPM: %d\n", i+1, practice_type[i], practice_hours[i], target_bpm[i], current_bpm[i]);
    }
}

// 3. 연산 함수
float calculate_average_BPM(int *bpm_arr, int count)
{
  int sum = 0;
  for(int i = 0; i<count; i++)
  {
    sum += *(bpm_arr + i);
  }
  return (sum*1.0f) / count;
}

float calculate_achievement(int current, int target)
{
  if(target == 0)
  {
    return 0.0;
  }
  return (current*100.0f) / target;
}

//4. 분석 출력 함수
void print_analysis_feedback(int *current_arr, int *target_arr)
{
  if(entry_count == 0)
  {
    printf("\n>> 분석할 데이터가 없습니다.\n");
    return;
  }

  int latest_idx = entry_count - 1;
  int current = current_arr[latest_idx];
  int target = target_arr[latest_idx];
  float achievement_rate = calculate_achievement(current, target);
  int remaining_bpm = target - current;

  printf("\n--- [3] 최신 연습 결과 분석 및 코칭 (Day %d) ---\n", latest_idx + 1);

  if(remaining_bpm <= 0)
  {
    printf("목표까지 남은 BPM:\t(목표 초과 달성!)\n");
  }
  else
  {
    printf("목표까지 남은 BPM:\t%d\n", remaining_bpm);
  }
  printf("현재 목표 달성률:\t%.2f%%\n", achievement_rate);

  printf("---------------------------------\n");
  printf("[연습 피드백]\n");
  //다중 조건문 및 관계연산자 및 관계연산자
  if(achievement_rate >= 100.0)
  {
    printf("축하합니다! 오늘의 목표 템포를 완벽하게 달성했습니다.\n");
    //중첩 조건문 및 논리 연산자
    if(practice_hours[latest_idx] >= 2.0 && practice_type[latest_idx] == 'R')
    {
      printf("2시간 이상의 맹연습과 루디먼트(R) 기초 훈련이 겹쳐 엄청난 성과를 냈군요! 최고입니다.\n");
    }
    else if(practice_hours[latest_idx] >= 2.0)
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
    if(remaining_bpm <= 10)
    {
      printf("목표 템포까지 고작 %d BPM 남았습니다! 메트로놈을 조금씩만 더 올려보세요.\n", remaining_bpm);
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
    if(practice_type[latest_idx] == 'S')
    {
      printf("곡(S) 연습 중이시군요! 무리해서 템포를 올리기보다는 정확한 박자와 그루브에 집중해 보세요.\n");
    }
    else
    {
      printf("조급해하지 말고 메트로놈과 친해지는 시간을 충분히 가져보세요. 파이팅!\n");
    }
  }
  float avg_bpm = calculate_average_BPM(current_arr, entry_count);
  printf("\n[누적 통계] 지금까지의 평균 도달 템포: %.1f BPM\n", avg_bpm);
}

int main()
{
  int menu_choice;

  while(1)
  {
    printf("\n=== 드럼 연습 종합 관리 시스템 ===\n");
    printf("1. 연습 기록 입력\n");
    printf("2. 전체 데이터 조회\n");
    printf("3. 최신 결과 분석 및 통계\n");
    printf("4. 프로그램 종료\n");
    printf("메뉴를 선택하세요 (1~4): ");
    scanf("%d", &menu_choice);

    if(menu_choice == 1)
    {
      input_practice_data();
    }
    else if(menu_choice == 2)
    {
      view_practice_data();
    }
    else if(menu_choice == 3)
    {
      print_analysis_feedback(current_bpm, target_bpm);
    }
    else if(menu_choice == 4)
    {
      printf("\n>> 시스템을 종료합니다. 오늘도 즐거운 연습 되셨길 바랍니다!\n");
      break;
    }
    else
    {
      printf("\n>> 잘못된 입력입니다. 1~4 사이의 숫자를 입력해주세요.\n");
    }

  }

  return 0;
}

    
