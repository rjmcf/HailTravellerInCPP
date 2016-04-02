#include "gtest/gtest.h"
#include "parser.h"

TEST(ParserTests, tokenStructTest)
{
    Tokens t("","");

    EXPECT_EQ(t.verb, "");
    EXPECT_EQ(t.noun, "");

    Tokens e("","");

    EXPECT_EQ(e.verb, "");
    EXPECT_EQ(e.noun, "");

    Tokens f("verb", "noun");

    EXPECT_EQ(f.noun, "noun");
    EXPECT_EQ(f.verb, "verb");
}

TEST(ParserTests, getTokenTest)
{
    Parser p;
    Tokens t = p.getTokens("");

    EXPECT_EQ(t.verb, "");
    EXPECT_EQ(t.noun, "");

    t = p.getTokens("look at houses");

    EXPECT_EQ(t.verb, "");
    EXPECT_EQ(t.noun, "");

    p.addVerb("look");

    t = p.getTokens("look at houses");

    EXPECT_EQ(t.verb, "look");
    EXPECT_EQ(t.noun, "");

    p.addNoun("houses");

    t = p.getTokens("look at houses");

    EXPECT_EQ(t.verb, "look");
    EXPECT_EQ(t.noun, "houses");

    p.clearNouns();

    t = p.getTokens("look at houses");

    EXPECT_EQ(t.verb, "look");
    EXPECT_EQ(t.noun, "");
}

TEST(ParserTests, exceptionTest)
{
    Parser p;

    p.addVerb("look");
    p.addVerb("move");
    try
    {
        Tokens t = p.getTokens("look and move");
        FAIL() << "No exception thrown";
    }
    catch (TwoVerbsException const &e)
    {
        EXPECT_TRUE(true);
    }
    catch (...)
    {
        FAIL() << "Wrong exception thrown";
    }


}
