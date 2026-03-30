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
    printf("\n--- 오늘의 연습 분석 결과 ---\n");
    printf("연습 종류:\t\t%c 타입\n", practice_type);
    printf("총 연습 시간:\t\t%.1f 시간\n", practice_hours);
    printf("목표 BPM:\t\t%d\n", target_bpm);
    printf("현재 최고 BPM:\t\t%d\n", current_bpm);
    printf("목표까지 남은 BPM:\t%d\n", bpm_remaining);
    printf("현재 목표 달성률:\t%.2f%%\n", achievement_rate);
    printf("==============================\n");

    return 0;
}
