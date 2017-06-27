#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	double tall = atof(argv[1]);
	int weight = atoi(argv[2]);
	double bmi = weight / (tall*tall);
	double std_weight = tall * tall * 22;
	printf("BMI: %lf\n", bmi);
	if(bmi < 18.5) printf("=> 低体重\n");
	else if(18.5 <= bmi && bmi < 25.0) printf("=> 標準\n");
	else if(25.0 <= bmi && bmi < 30.0) printf("=> 肥満\n");
	else printf("高度肥満\n");
	printf("標準体重: %lf\n", std_weight);
	return 0;
}