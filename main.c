//  Created by Connor Larson on 2/5/25.


#include <stdio.h>
#include <string.h>

int main() {
   const double HOMEWORK_MAX = 800.0;
   const double QUIZZES_MAX = 400.0;
   const double MIDTERM_MAX = 150.0;
   const double FINAL_MAX = 200.0;
   
   char studentStatus;
   double homeworkPoints;
   double quizPoints;
   double midtermScore;
   double finalScore;
   
   double homeworkAvg;
   double quizAvg;
   double midtermAvg;
   double finalAvg;
   
   double classAvg;
   char classGrade;
   
   scanf("%c", &studentStatus);
   scanf("%lf", &homeworkPoints);
   scanf("%lf", &quizPoints);
   scanf("%lf", &midtermScore);
   scanf("%lf", &finalScore);
   
   
   homeworkAvg = (homeworkPoints / HOMEWORK_MAX) * 100.0;
   quizAvg = (quizPoints / QUIZZES_MAX) * 100.0;
   midtermAvg = (midtermScore / MIDTERM_MAX) * 100.0;
   finalAvg = (finalScore / FINAL_MAX) * 100.0;
   
   if (homeworkAvg > 100.0) {
      homeworkAvg = 100.0;
   }
   if (quizAvg > 100.0) {
      quizAvg = 100.0;
   }
   if (midtermAvg > 100.0) {
      midtermAvg = 100.0;
   }
   if (finalAvg > 100.0) {
      finalAvg = 100.0;
   }

   //Valid student statuses
   if (studentStatus == 'U' || studentStatus == 'G' || studentStatus == 'D') {
      
      //calulate class average based on how each section is weighted, ie homework is 20%, final is 30%
      switch (studentStatus) {
         case 'U':
            classAvg = ((homeworkAvg / 100.0) * 20.0) + ((quizAvg / 100.0) * 20.0)
                     + ((midtermAvg / 100.0) * 30.0) + ((finalAvg / 100.0) * 30.0);
            break;
         case 'G':
            classAvg = ((homeworkAvg / 100.0) * 15.0) + ((quizAvg / 100.0) * 5.0)
                     + ((midtermAvg / 100.0) * 35.0) + ((finalAvg / 100.0) * 45.0);
            break;
         case 'D':
            classAvg = ((homeworkAvg / 100) * 5.0) + ((quizAvg / 100.0) * 5.0)
                     + ((midtermAvg / 100.0) * 40.0) + ((finalAvg / 100.0) * 50.0);
            break;
      }
      
      if (classAvg >= 90) {
         classGrade = 'A';
      }
      else if (classAvg >= 80 && classAvg < 90) {
         classGrade = 'B';
      }
      else if (classAvg >= 70 && classAvg < 80) {
         classGrade = 'C';
      }
      else if (classAvg >= 60 && classAvg < 90) {
         classGrade = 'D';
      }
      else {
         classGrade = 'F';
      }
      
      printf("Homework: %.1f%%\n", homeworkAvg);
      printf("Quizzes: %.1f%%\n", quizAvg);
      printf("Midterm: %.1f%%\n", midtermAvg);
      printf("Final Exam: %.1f%%\n", finalAvg);
      printf("%c average: %.1lf%%\n", studentStatus, classAvg);
      printf("Course grade: %c\n", classGrade);
   }
   else {
      printf("Error: student status must be U, G or D\n");
   }
   
   return 0;
}
