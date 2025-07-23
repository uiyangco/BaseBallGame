#include <stdexcept>

using namespace std;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class BaseBall
{
public:
	BaseBall(const string& question) : question{question} {}

	GuessResult Guess(const string& guessNumber)
	{
		AssertIllegalArgument(guessNumber);

		if (guessNumber == question)
		{
			return { true, 3, 0 };
		}

		int strikes = CheckStrikes(guessNumber);
		int balls = CheckBalls(guessNumber);

		return { false, strikes, balls };
	}

private:
	string question;

	void AssertIllegalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3)
		{
			throw length_error("Must be three letter.");
		}

		for (char ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (HasDuplicatedNumber(guessNumber))
		{
			throw invalid_argument("Must not have same number");
		}
	}

	bool HasDuplicatedNumber(const string& guessNumber)
	{
		if (guessNumber[0] == guessNumber[1])
		{
			return true;
		}

		if (guessNumber[0] == guessNumber[2])
		{
			return true;
		}

		if (guessNumber[1] == guessNumber[2])
		{
			return true;
		}
		return false;
	}

	int CheckStrikes(const string& guessNumber)
	{
		int strikes = 0;
		for (int charPosition = 0; charPosition < question.length(); charPosition++)
		{
			if (question[charPosition] == guessNumber[charPosition])
			{
				strikes++;
			}
		}
		return strikes;
	}

	int CheckBalls(const string& guessNumber)
	{
		int balls = 0;
		for (int questionCharPosition = 0; questionCharPosition < question.length(); questionCharPosition++)
		{
			for (int guessNumberCharPosition = 0; guessNumberCharPosition < guessNumber.length(); guessNumberCharPosition++)
			{
				if (questionCharPosition == guessNumberCharPosition) continue;
				if (question[questionCharPosition] == guessNumber[guessNumberCharPosition])
				{
					balls++;
				}
			}
		}
		return balls;
	}
};