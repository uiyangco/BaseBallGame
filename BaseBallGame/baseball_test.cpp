#include "gmock/gmock.h"
#include "baseball.cpp"


class BaseBallGame : public testing::Test
{
public:
	BaseBall game{ "123" };
	void assertIllegalArgument(string guessNumber)
	{
		try
		{
			game.Guess(guessNumber);
			FAIL();
		}
		catch (exception e)
		{

		}
	}
};

TEST_F(BaseBallGame, ExceptionCaseWhenInputInvalidCase)
{
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseBallGame, NormalCase1)
{
	GuessResult result = game.Guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseBallGame, NormalCase2)
{
	GuessResult result = game.Guess("124");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseBallGame, NormalCase3)
{
	GuessResult result = game.Guess("132");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}

TEST_F(BaseBallGame, NormalCase4)
{
	GuessResult result = game.Guess("312");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(0, result.strikes);
	EXPECT_EQ(3, result.balls);
}