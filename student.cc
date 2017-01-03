#include <stdio.h>
int main() {
  struct stu{
    char *name;
    int num;
    int age;
    char group;
    float score;
  } stu2;

  struct stu stu1;

  stu1.name = "Tom";
  stu1.num = 12;
  stu1.age = 18;
  stu1.group = 'A';
  stu1.score = 136.5;

  printf("%s的学号是%d, 年龄是%d, 在%c组, 今年的成绩是%.1f!\n", stu1.name,
      stu1.num, stu1.age, stu1.group, stu1.score);

  return 0;
}
