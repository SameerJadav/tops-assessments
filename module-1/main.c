#include <stdio.h>

// Displays the calculator menu
void displayMenu() {
  printf("----------Menu----------\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n\n");
}

// Prompts user to continue or exit the program
char promptContinue() {
  char ch;
  printf("\nDo you want to continue (y/n)? ");
  scanf(" %c", &ch);
  return ch;
}

// Print newline for formatting if continuing
void printNewline(char ch) {
  if (ch == 'y' || ch == 'Y') {
    printf("\n");
  }
}

int main() {
  char ch;

  do {
    displayMenu();

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice > 4 || choice < 1) {
      printf("\nInvalid choice!!!\n");

      ch = promptContinue();

      printNewline(ch);

    } else {

      int num1;
      printf("\nEnter first number: ");
      scanf("%d", &num1);

      int num2;
      printf("Enter second number: ");
      scanf("%d", &num2);

      switch (choice) {
      case 1:
        printf("\nAddition: %d\n", num1 + num2);
        break;
      case 2:
        printf("\nSubtraction: %d\n", num1 - num2);
        break;
      case 3:
        printf("\nMultiplication: %d\n", num1 * num2);
        break;
      case 4:
        printf("\nDivision: %f\n", (float)num1 / (float)num2);
        break;
      }

      ch = promptContinue();

      printNewline(ch);
    }
  } while (ch == 'y' || ch == 'Y');

  return 0;
}
