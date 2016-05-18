/**
 * Unit Tests for GoalUndo class
 * By Amit Shinde - 006955001
 * For CSCI 630 - Spring 2016
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"
 
class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};
//Sanity Check
TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

/*  checkNewGoal
    Add a new goal using addOperation(goal,op) 
    and check to see if it shows up in 
    getGoal()
*/
TEST(GoalUndoTest, checkNewGoal)
{
    GoalUndo gun;
    gun.addOperation("goal1","op1");
    ASSERT_EQ("goal1",gun.getGoal());
}

/*  checkNewGoalbyOpAdd
    Add a new operation using addOperation(op)
    and check to see if it shows up in getGoal()
*/
TEST(GoalUndoTest, checkNewGoalbyOpAdd)
{
    GoalUndo gun;
    gun.addOperation("op1");
    ASSERT_EQ("op1",gun.getGoal());
}

/*  checkNewOpbyOpAdd
    Add a new operation using addOperation(op)
    and check to see if it shows up in 
    getOperations()
*/
TEST(GoalUndoTest, checkNewOpbyOpAdd)
{
    GoalUndo gun;
    gun.addOperation("op1");
    ASSERT_EQ("op1",gun.getOperations());
}
/*  checkNewOp  
    Add a new opreation using addOperation(goal,op)
    and check to see if it shows up in
    getOperations()
*/
TEST(GoalUndoTest, checkNewOp)
{
    GoalUndo gun;
    gun.addOperation("goal1","op1");
    ASSERT_EQ("op1",gun.getOperations());
}

/*  checkEmptyGoal
    Check if any goal exits without creating
    a new goal/operation
*/
TEST(GoalUndoTest, checkEmptyGoal)
{
    GoalUndo gun;
    ASSERT_EQ("",gun.getGoal());
}


/*  checkEmptyOp
    Check if any operation exits without creating
    a new goal/operation
*/
TEST(GoalUndoTest, checkEmptyOp)
{
    GoalUndo gun;
    ASSERT_EQ("",gun.getOperations());
}

/*  checkEmptyGoalAdd
    Add goal with empty string and check
    if gets added. 
*/
TEST(GoalUndoTest, checkEmptyGoalAdd)
{
    GoalUndo gun;
    gun.addOperation("");
    ASSERT_EQ("",gun.getGoal());
}

/*  checkEmptyOpAdd
    Add operations with empty string and check
    if it gets addded
*/
TEST(GoalUndoTest, checkEmptyOpAdd)
{
    GoalUndo gun;
    gun.addOperation("");
    ASSERT_EQ("",gun.getOperations());
}

/*  checkundoGoal
    Add goal and call undoGoal. Check if
    getGoal returns empty string after this
    to ensure undoGoal works
*/
TEST(GoalUndoTest, checkundoGoal)
{
    GoalUndo gun;
    gun.addOperation("g1","op1");
    gun.undoGoal();
    ASSERT_EQ("",gun.getGoal());
}


/*  checkEmptyundoGoal
    Dont add any goal and call undoGoal. Check if
    getGoal returns empty string after this
    to ensure undoGoal works
*/
TEST(GoalUndoTest, checkEmptyUndoGoal)
{
    GoalUndo gun;
    gun.undoGoal();
    ASSERT_EQ("",gun.getGoal());
}


/*  checkundoOps
    Add goal/operations and call undoOperation(). 
    Check if getOperations() returns empty string 
    after this to ensure undoGoal works
*/
TEST(GoalUndoTest, checkundoOps)
{
    GoalUndo gun;
    gun.addOperation("g1","op1");
    gun.undoOperation();
    ASSERT_EQ("",gun.getOperations());
}

/*  checkEmptyundoOps
    Call undoOpertaion() without adding any
    operations and check if getOperations()
    returns empty string.
*/
TEST(GoalUndoTest, checkEmptyundoOps)
{
    GoalUndo gun;
    gun.undoOperation();
    ASSERT_EQ("",gun.getOperations());
}

/*  checkundoGoalbyUndoLastOps
    Add a goal and operation, call undoOperation()
    and check it cleans up the goal as well by
    calling getGoal()
*/
TEST(GoalUndoTest, checkundoGoalbyUndoLastOps)
{
    GoalUndo gun;
    gun.addOperation("g1","op1");
    gun.undoOperation();
    ASSERT_EQ("",gun.getGoal());
}

/*  checkundoLastOps
    Add a goal and a bunch of operations and
    call undoOperation(op) on the last op name and
    see if it shows up in getOperations()
*/
TEST(GoalUndoTest, checkundoLastOps)
{
    GoalUndo gun;
    gun.addOperation("g1","op1");
    gun.addOperation("op2");
    gun.addOperation("op3");
    gun.addOperation("op4");
    gun.addOperation("op5");
    gun.addOperation("op6");
    gun.undoOperation("op6");
    ASSERT_EQ("op1 op2 op3 op4 op5",gun.getOperations());
}

/*  checkundoMidOps
    Add a goal and a bunch of operations and
    call undoOperation(op) on an op name in the middle and
    see if it shows up in getOperations()
*/
TEST(GoalUndoTest, checkundoMidOps)
{
    GoalUndo gun;
    gun.addOperation("g1","op1");
    gun.addOperation("op2");
    gun.addOperation("op3");
    gun.addOperation("op4");
    gun.addOperation("op5");
    gun.addOperation("op6");
    gun.undoOperation("op3");
    ASSERT_EQ("op1 op2 op4 op5 op6",gun.getOperations());
}

/*  checkundoFirstOps
    Add a goal and a bunch of operations and
    call undoOperation(op) on the first op and
    see if it shows up in getOperations()
*/
TEST(GoalUndoTest, checkundoFirstOp)
{
    GoalUndo gun;
    gun.addOperation("g1","op1");
    gun.addOperation("op2");
    gun.addOperation("op3");
    gun.addOperation("op4");
    gun.addOperation("op5");
    gun.addOperation("op6");
    gun.undoOperation("op1");
    ASSERT_EQ("op2 op3 op4 op5 op6",gun.getOperations());
}

/*  addDuplicateGoal
    Check to see if you can add duplicate goal
    and verify by calling getGoal()
*/
TEST(GoalUndoTest, addDuplicateGoal)
{
    GoalUndo gun;
    gun.addOperation("g1","op1");
    gun.addOperation("g2","op3");
    gun.addOperation("g1","op2");
    ASSERT_EQ("g1",gun.getGoal());
}

/*  checkOpinDupGoal
    Add duplicate goal and add an operation to it.
    Call getOperations to see if thats the only op
    that shows up.
*/
TEST(GoalUndoTest, checkOpinDupGoal)
{
    GoalUndo gun;
    gun.addOperation("g1","op1");
    gun.addOperation("g2","op3");
    gun.addOperation("g1","op2");
    ASSERT_EQ("op2",gun.getOperations());
}

/*  checkSpecialCharinGoal
    Add new goal/operation with special characters in the name.
    Check to see if the new goal is added using getGoal()
*/
TEST(GoalUndoTest, checkSpecialCharinGoal)
{
    GoalUndo gun;
    gun.addOperation("\b\t\n\**\&&%d%s\$$\##\@@\!!\~~\( \)\b\t\n");
    ASSERT_EQ("\b\t\n\**\&&%d%s\$$\##\@@\!!\~~\( \)\b\t\n",gun.getGoal());
}

/*  checkSpecialCharinOps
    Add new goal/operation with special characters in the name.
    Check to see if the new operation is added using getOperations()
*/
TEST(GoalUndoTest, checkSpecialCharinOps)
{
    GoalUndo gun;
    gun.addOperation("\b\t\n\**\&&%d%s\$$\##\@@\!!\~~\( \)\b\t\n");
    ASSERT_EQ("\b\t\n\**\&&%d%s\$$\##\@@\!!\~~\( \)\b\t\n",gun.getOperations());
}
