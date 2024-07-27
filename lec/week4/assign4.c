#include <stdio.h>

void getFloatInput(char *str, float *f)
{
    printf("%s", str);
    scanf("%f", f);
}
void rectangleArea(float w, float l, float *area)
{
    *area = w * l;
}
void showRecArea(float *area)
{
    printf("Rectangle area is %.2f\n", *area);
}
int main()
{
    float width, length, area;
    getFloatInput("Enter width : ", &width);
    getFloatInput("Enter length : ", &length);
    rectangleArea(width, length, &area);
    showRecArea(&area);
    return 0;
}
//ศิริสุข ทานธรรม 6610402230