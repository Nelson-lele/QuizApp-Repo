#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Quiz
{
	char userChoice;
	std::vector<std::string> questions;
	std::vector<char> answerTag;
	std::vector<char> userAnswers;

	

	int  calculateScores()
	{	
		int score = 0;
;

		for (int i = 0; i < answerTag.size(); i++) {
			if (answerTag[i] == userAnswers[i])
				score++;
			
		}
		return score;
		
	}
};



Quiz quiz;

namespace Tests
{
	void ReadQuestionFromFile(const std::string& filename)
	{
		std::ifstream file;

		file.open(filename);
		std::string lines;
		if (file.is_open()) {
			while (!file.eof()) {
				getline(file, lines);
				quiz.questions.push_back(lines);
			}
			file.close();
		}
		else
			std::cout << "Unable to open file" << std::endl;
	}
	void LoadAnswerFromFile(const std::string& filename)
	{
		std::ifstream file;
		char lines;

		file.open(filename);
		if (file.is_open()) {
			while (!file.eof()) {
				file >> lines;
				quiz.answerTag.push_back(lines);
			}

			file.close();
			quiz.answerTag.pop_back();

		}
		else {
			std::cout << "Unable to open file" << std::endl;
		}
	}
	void DisplayScores(Quiz& q)
	{	
		int scores = q.calculateScores();
		//double percent = scores / q.answerTag.size() * 100;
		std::cout << "\t\t\t  SCORES DETAILS" << std::endl;
		std::cout << std::endl;
		std::cout << "\t\t\tScores: " << scores << "/" << q.answerTag.size() << std::endl;


		std::cout << "Correct Answers: ";
		for (auto character : q.answerTag)
			std::cout << character << " ";
		std::cout << std::endl;
		std::cout << "Your Answer : ";
		for (auto character : q.userAnswers)
			std::cout  << character << " ";
		std::cout << std::endl;
	}
	void GetAnswers()
	{
		std::cout << "Enter choice (a-d): ";
		std::cin >> quiz.userChoice;

		quiz.userChoice = std::tolower(quiz.userChoice);

		quiz.userAnswers.push_back(quiz.userChoice);

	}
	void ReadQuestion(const Quiz& q)
	{
		int len = q.questions.size();

		for (int i = 0; i < len; i++) {
			int k = 5;
			std::cout << q.questions[i] << std::endl;
			for (int j = i; j < len; j++) {
				if (j == k)
					GetAnswers();
				k += 7;
	

			}
			
		}
	}
}


int main()
{

	Tests::ReadQuestionFromFile("question.txt");
	Tests::LoadAnswerFromFile("answers.txt");

	Tests::ReadQuestion(quiz);
	
	Tests::DisplayScores(quiz);


	std::cin.get();
}