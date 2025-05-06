//Morgan Bocobo
// 05/2/2025
// Project 10 Wordup

	#include <stdio.h>
	#define FILE_NAME "word.txt"

void fileWord(char answer[]);
void userGuess(char guesses[][6], int attempt);
void checkGuess(char guess[], char answer[]);
void isCorrect(char guess[], char answer[], int *correct);
void winMessage(int attempts);
void loseMessage(char answer[]);

int main(){
	
	char guess[5][6];
	char answer[6];
	int attempts = 0;
	int correct = 0;
	
	fileWord(answer);
		
		while(attempts < 5 && !correct){
			userGuess(guess, attempts);
			checkGuess(guess[attempts], answer);
			isCorrect(guess[attempts], answer, &correct);
			attempts++;
		}
			if (correct){
				winMessage(attempts);
			}
		else{
			loseMessage(answer);
		}
		
	return 0;
}
	

void fileWord(char answer[]){
	
	FILE *fp1;
		fp1 = fopen(FILE_NAME, "r");
		if (fp1 == NULL){
			printf("Cannot open file\n");
			}
		//look at lab 12
	fscanf(fp1, "%s", answer);
	fclose(fp1);
}

void userGuess(char guesses[][6], int attempt){
	int length;
//do While loop kind of like menu, to get the guesses
	
	do{
		length = 0;
		printf("Guess %d:\n", attempt +1); //add one so exactly 5
		scanf("%s", guesses[attempt]);
	//checking if word is 5 letters
		while(guesses[attempt][length] != '\0'){
			length++;
	}
	if(length != 5){
		printf("Word must be 5 letters, Try again:\n");
		}
	}while(length != 5);
}

void checkGuess(char guess[], char answer[]){
	//capitilize letters if in correct spot and correct guess
	for(int i = 0; i < 5; i++){
		if(guess[i] == answer [i]){
			if(guess[i] >= 'a' && guess[i] <= 'z'){
			printf("%c", guess[i] - 32);
		} 
		else{
			printf("%c", guess[i]);
			}
		}
		else{
			printf("%c", guess[i]);
		}
	}
	printf("\n");
	//the '^' hints
	for(int i = 0; i < 5; i++){
		if(guess[i] == answer[i]){
		printf(" ");
	}
	else{
		int hint = 0;
		for(int j = 0; j < 5; j++){
			if(guess[i] == answer[j]){
			hint = 1;
			}
		}
	if(hint == 1){
		printf("^");
	}
	else{
		printf(" ");
		}
	}
}
printf("\n");
}
		
//pass by adress here, refrence the lab
void isCorrect(char guess[], char answer[], int *correct){
	
	int correctGuess = 1;
		for(int i = 0; i <5; i++){
			if(guess[i] != answer[i]){
			correctGuess = 0;
		}
	}
	*correct = correctGuess;
}

void winMessage(int attempts){
	printf("You guessed it in %d guesses!\nGREAT JOB :D!\n", attempts);
	printf("\n");

}

void loseMessage(char answer[]){
	
	printf("You ran out of guesses :(!\n The correct answer was: %s\n", answer);
}





