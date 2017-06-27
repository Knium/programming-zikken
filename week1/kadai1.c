#include <stdio.h>
#include <math.h>

#define NUM_OF_MEMBER 11

typedef struct {
	int index;
	int tall;
	int weight;
} human;

void show_profile(human *people) {
	int i;
	// printf("----------\n");
	printf("---番号---身長(cm)---体重 (kg)---\n");
	for(i = 0; i < NUM_OF_MEMBER; i++){
		if(i + 1< 10)printf("|   %d    |    %d    |    %d    |\n", i+1, people[i].tall, people[i].weight);
		else printf("|   %d   |    %d    |    %d    |\n", i+1, people[i].tall, people[i].weight);
		// printf("----------\n");
		printf("---------------------------------\n");
	}
}

void sort(int *array){
	int i,j,temp;
	for(i = 0; i < NUM_OF_MEMBER; i++){
		for(j = 0;j < NUM_OF_MEMBER; j++){
			if (array[j] < array[i]){
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
}

int max_tall(human *people){
	int max, i;
	max = people[0].tall;
	for(i = 1; i < NUM_OF_MEMBER; i++){
		if(max < people[i].tall) max =  people[i].tall;
	}
	return max;
}

int max_weight(human *people){
	int max, i;
	max = people[0].weight;
	for(i = 1; i < NUM_OF_MEMBER; i++){
		if(max < people[i].weight) max =  people[i].weight;
	}
	return max;
}

int min_tall(human *people){
	int min, i;
	min = people[0].tall;
	for(i = 1; i < NUM_OF_MEMBER; i++){
		if(min > people[i].tall) min =  people[i].tall;
	}
	return min;
}

int min_weight(human *people){
	int min, i;
	min = people[0].weight;
	for(i = 1; i < NUM_OF_MEMBER; i++){
		if(min > people[i].weight) min =  people[i].weight;
	}
	return min;
}

double average_tall(human *people){
	int i;
	int sum = 0;
	for(i = 0; i < NUM_OF_MEMBER; i++){
		sum += people[i].tall;
	}
	return sum/NUM_OF_MEMBER;
}

double average_weight(human *people){
	int i;
	int sum = 0;
	for(i = 0; i < NUM_OF_MEMBER; i++){
		sum += people[i].weight;
	}
	return sum/NUM_OF_MEMBER;
}


int median_weight(human *people){
	int i, weights[NUM_OF_MEMBER];
	for(i = 0; i < NUM_OF_MEMBER; i++){
		weights[i] = people[i].weight;
	}
	sort(weights);
	return weights[5]; // 中央値
}


int median_tall(human *people){
	int i, talls[NUM_OF_MEMBER];
	for(i = 0; i < NUM_OF_MEMBER; i++){
		talls[i] = people[i].tall;
	}
	sort(talls);
	return talls[5]; // 中央値
}


double standard_deviation_tall(human *people){
	int i, result;
	double average = average_tall(people);
	int sum = 0;
	for(i = 0; i < NUM_OF_MEMBER; i++){
		sum += (people[i].tall - average) * (people[i].tall - average);
	}
	return sqrt(sum/NUM_OF_MEMBER);
}

double standard_deviation_weight(human *people){
	int i, result;
	double average = average_weight(people);
	int sum = 0;
	for(i = 0; i < NUM_OF_MEMBER; i++){
		sum += (people[i].weight - average) * (people[i].weight - average);
	}
	return sqrt(sum/NUM_OF_MEMBER);
}

double correlation_coefficient(human *people){
	double demoninator = standard_deviation_tall(people) * standard_deviation_weight(people);
	double sum;
	double a_tall = average_tall(people);
	double a_weight = average_weight(people);
	int i;
	for(i = 0; i < NUM_OF_MEMBER; i++){
		sum += (people[i].tall - a_tall) * (people[i].weight - a_weight);
	}
	return (sum / NUM_OF_MEMBER) / demoninator;
}

int main(int argc, char const *argv[]){
	human people[11] = {
		{1, 168, 60},
		{2, 162, 55},
		{3, 171, 65},
		{4, 159, 60},
		{5, 174, 72},
		{6, 166, 57},
		{7, 175, 61},
		{8, 176, 66},
		{9, 168, 56},
		{10, 182, 69},
		{11, 179, 62}
	};
	show_profile(people);
	printf("身長最大値: %d\n", max_tall(people));
	printf("身長最小値: %d\n", min_tall(people));
	printf("体重最大値: %d\n", max_weight(people));
	printf("体重最小値: %d\n", min_weight(people));
	printf("身長平均値: %lf\n", average_tall(people));
	printf("体重平均値: %lf\n", average_weight(people));
	printf("身長中央値: %d\n", median_tall(people));
	printf("体重中央値: %d\n", median_weight(people));
	printf("身長標準偏差: %lf\n", standard_deviation_tall(people));
	printf("体重標準偏差: %lf\n", standard_deviation_weight(people));
	printf("身長と体重の相関係数: %lf\n", correlation_coefficient(people));
	return 0;
}