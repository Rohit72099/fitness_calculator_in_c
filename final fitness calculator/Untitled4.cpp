#include <stdio.h>

struct User {
  char gender;
  int age;
  float height, weight;
};

int main() {
  int choice;
  float bmi, bmr, bodyfat, idealWeight;
	FILE *fp;
  fp = fopen("output.txt", "w");


  printf("Welcome to the Fitness Calculator!\n");

  // get user input
  struct User user;
  printf("Enter your gender (M/F): ");
  scanf(" %c", &user.gender);
  printf("Enter your age in years: ");
  scanf("%d", &user.age);
  printf("Enter your height in meters: ");
  scanf("%f", &user.height);
  printf("Enter your weight in kilograms: ");
  scanf("%f", &user.weight);

  // get user's calculation choice
  printf("\nWhat do you want to calculate?\n");
  printf("1. Calculate Body Mass Index (BMI)\n");
  printf("2. Calculate Basal Metabolic Rate (BMR)\n");
  printf("3. Calculate body fat\n");
  printf("4. Ideal weight calculator\n");
  scanf("%d", &choice);

  //FILE *fp;
  //fp = fopen("output.txt", "w");

  switch(choice) {
    case 1:
      bmi = user.weight / (user.height * user.height);
      fprintf(fp, "BMI is %.2f\n", bmi);
      if (bmi < 16)
        fprintf(fp, "You are severely thin\n");
      else if (bmi < 17)
        fprintf(fp, "You are moderately thin\n");
      else if (bmi < 18.5)
        fprintf(fp, "You are mildly thin\n");
      else if (bmi < 25)
        fprintf(fp, "You are normal\n");
      else if (bmi < 30)
        fprintf(fp, "You are overweight\n");
      else
        fprintf(fp, "You are obese\n");
      break;
    case 2:
      if (user.gender == 'M')
        bmr = 88.362 + (13.397 * user.weight) + (4.799 * user.height * 100) - (5.677 * user.age);
      else if (user.gender == 'F')
        bmr = 447.593 + (9.247 * user.weight) + (3.098 * user.height * 100) - (4.330 * user.age);
      else {
        fprintf(fp, "Invalid gender entered.\n");
        return 0;
      }
      fprintf(fp, "Your BMR is %.2f calories/day\n", bmr);
      break;
    case 3:
      bmi = user.weight / (user.height * user.height);
      bodyfat = (1.20 * bmi) + (0.23 * user.age) - 5.4;
      fprintf(fp, "Your body fat is %.2f%%\n", bodyfat);
      break;
    case 4:
      if (user.gender == 'M')
        idealWeight = 50 + (0.91 * (user.height * 100 - 152.4));
      else if (user.gender == 'F')
        idealWeight = 45.5 + (0.91 * (user.height * 100 - 152.4));
      else {
        fprintf(fp, "Invalid gender entered.\n");
        return 0;
      }
      fprintf(fp, "Your ideal weight is %.2f kg\n", idealWeight);
      break;
    default:
      fprintf(fp, "Invalid choice entered.\n");
      
  }

  fclose(fp);
  
  
  return 0;
}

  

