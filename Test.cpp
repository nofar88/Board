#include "doctest.h"
#include "Direction.hpp"
#include "Board.hpp"
using namespace ariel;

#include <string>
using namespace std;


TEST_CASE("Good case code") {
    Board board;
    // Both case
    CHECK_NOTHROW(board.post(100,200,Direction::Horizontal,"nofar"));
    CHECK(board.read(100,200,Direction::Horizontal,0) ==string(""));
    CHECK(board.read(100,200,Direction::Horizontal,1) == string("n"));
    CHECK(board.read(100,200,Direction::Horizontal,2) == string("no"));
    CHECK(board.read(100,200,Direction::Horizontal,3) ==string("nof"));
    CHECK(board.read(100,200,Direction::Horizontal,4) == string("nofa"));
    CHECK(board.read(100,200,Direction::Horizontal,5) == string("nofar"));
    CHECK(board.read(100,200,Direction::Vertical,0) == string(""));
    CHECK(board.read(100,200,Direction::Vertical,1) == string("n"));
    CHECK(board.read(100,200,Direction::Vertical,2) == string("n_"));
    CHECK(board.read(100,201,Direction::Vertical,3) == string("o__"));
    CHECK(board.read(100,202,Direction::Vertical,3) == string("f__"));

    CHECK(board.read(100,250,Direction::Vertical,3) == string("___"));
    CHECK(board.read(100,204,Direction::Vertical,3) == string("r__"));
    CHECK_NOTHROW(board.post(100,200,Direction::Horizontal,"abc"));
    CHECK(board.read(100,200,Direction::Horizontal,1) == string("a"));
    CHECK(board.read(100,200,Direction::Horizontal,2) == string("ab"));
    CHECK(board.read(100,200,Direction::Horizontal,3) == string("abc"));
    CHECK(board.read(100,200,Direction::Horizontal,4) == string("abca"));
    CHECK(board.read(100,200,Direction::Horizontal,5) == string("abcar"));
    CHECK_NOTHROW(board.post(100,202,Direction::Vertical,"xyz"));
    CHECK(board.read(100,200,Direction::Horizontal,3) == string("abx"));
    CHECK(board.read(100,200,Direction::Horizontal,5) == string("abxar"));
    CHECK(board.read(100,200,Direction::Vertical,3) == string("a__"));
    CHECK(board.read(101,200,Direction::Vertical,2) == string("__"));
    CHECK(board.read(100,202,Direction::Vertical,3) == string("xyz"));
    CHECK(board.read(99,202,Direction::Vertical,3) == string("_xy"));


//("Vertical good case code")
    
    CHECK_NOTHROW(board.post(100,202,Direction::Vertical,"abcd"));
    CHECK(board.read(100,202,Direction::Vertical,0) == string(""));
    CHECK(board.read(100,202,Direction::Vertical,1) == string("a"));
    CHECK(board.read(100,202,Direction::Vertical,2) == string("ab"));
    CHECK(board.read(100,202,Direction::Vertical,3) == string("abc"));
    CHECK(board.read(100,202,Direction::Vertical,4) == string("abcd"));
    CHECK(board.read(100,202,Direction::Vertical,5) == string("abcd_"));
    CHECK(board.read(100,201,Direction::Vertical,6) == string("b_____"));
    
    CHECK_NOTHROW(board.post(103,204,Direction::Vertical,"p"));
    CHECK(board.read(103,204,Direction::Vertical,0) == string(""));
    CHECK(board.read(103,204,Direction::Vertical,1) == string("p"));
    CHECK(board.read(102,204,Direction::Vertical,2) == string("_p"));
    CHECK(board.read(102,204,Direction::Vertical,3) == string("_p_"));
    CHECK(board.read(100,204,Direction::Vertical,4) == string("r__p"));
     



//("Horizontal good case code") 
    
    CHECK_NOTHROW(board.post(103,202,Direction::Horizontal,"good"));
    CHECK(board.read(103,202,Direction::Horizontal,0) == string(""));
    CHECK(board.read(103,202,Direction::Horizontal,1) == string("g"));
    CHECK(board.read(103,202,Direction::Horizontal,2) == string("go"));
    CHECK(board.read(103,202,Direction::Horizontal,3) == string("goo"));
    CHECK(board.read(103,202,Direction::Horizontal,4) == string("good"));
    CHECK(board.read(103,202,Direction::Horizontal,5) == string("good_"));
    CHECK(board.read(103,201,Direction::Horizontal,6) == string("_good_"));
    
    CHECK_NOTHROW(board.post(103,206,Direction::Horizontal,"!"));
    CHECK(board.read(103,202,Direction::Horizontal,0) == string(""));
    CHECK(board.read(103,202,Direction::Horizontal,1) == string("g"));
    CHECK(board.read(103,202,Direction::Horizontal,2) == string("go"));
    CHECK(board.read(103,202,Direction::Horizontal,3) == string("goo"));
    CHECK(board.read(103,202,Direction::Horizontal,4) == string("good"));
    CHECK(board.read(103,202,Direction::Horizontal,5) == string("good!"));
    CHECK(board.read(103,201,Direction::Horizontal,6) == string("_good!"));   

}

TEST_CASE("Vertical long good case code") {
    Board board;
    CHECK_NOTHROW(board.post(200,100,Direction::Vertical,"my name is"));
    CHECK(board.read(200,100,Direction::Vertical,0) == string(""));
    CHECK(board.read(200,100,Direction::Vertical,1) == string("m"));
    CHECK(board.read(200,100,Direction::Vertical,2) == string("my"));
    CHECK(board.read(200,100,Direction::Vertical,3) == string("my "));
    CHECK(board.read(200,100,Direction::Vertical,4) == string("my n"));
    CHECK(board.read(200,100,Direction::Vertical,5) == string("my na"));
    CHECK(board.read(200,100,Direction::Vertical,6) == string("my nam"));
    CHECK(board.read(200,100,Direction::Vertical,7) == string("my name"));
    CHECK(board.read(200,100,Direction::Vertical,8) == string("my name "));
    CHECK(board.read(200,100,Direction::Vertical,10) == string("my name is"));
    }




// TEST_CASE("Bad case code") {
//     Board board;
//     CHECK_THROWS(board.post(-103,-205,Direction::Horizontal,"!"));
//     CHECK_THROWS_AS(board.read(-103,-205,Direction::Horizontal,2) , std::range_error);
    
//     CHECK_THROWS(board.post(1,-100,Direction::Horizontal,"!"));
//     CHECK_THROWS_AS(board.read(-103,-205,Direction::Horizontal,2) , std::invalid_argument);
// }