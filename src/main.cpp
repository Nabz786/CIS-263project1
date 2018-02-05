#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <algorithm>
#include <string>
#include "AUDS.h"
#include "catch.hpp"
#include "stdio.h"
// Test cases take two parameters - the first is a test
// name and the second is a tag.
// This test merely checks that 1 is equal to 1.  It
// should always pass.  It is included here to show `how
// to write test cases.

TEST_CASE( "Constructor test", "[creation]" ){
	AUDS<int> a;
	AUDS<float> b;
	AUDS<AUDS<int> > c;
	CHECK( a.size() == 0 );
	CHECK( b.size() == 0 );
	CHECK( c.size() == 0 );
}

TEST_CASE( "Push test", "[inner]" ){
	AUDS<int> a;
	for(int i=0; i<1000; i++){
		a.push(i);
		std::cout << "current size: "  << a.size() << std::endl;
	}
	CHECK( a.size() == 1000 );
}

TEST_CASE( "Pop test", "[inner]" ){
	AUDS<std::string> s;
	for(int i=0; i<1000; i++){
		s.push("Item " + std::to_string(i));
	//	std::cout << s.size() << std::endl;
	}
	

	for(int i=0; i<500; i++){
		std::cout << s.pop() << std::endl;
		//std::cout << "Current Size: "  << s.size() << std::endl;
		//std::cout << "Random Val: " << s.getRandomIndex() << std::endl;
	}
	CHECK( s.size() == 500 );
}

TEST_CASE("Another pop test", "[inner]"){
	AUDS<int> ss;
	for(int i = 0; i<100; i++){
		ss.push(i);
	}

	for(int j = 0; j < 50; j++){
		std::cout << ss.pop() << std::endl;
	}
	CHECK(ss.size() == 50);
}

TEST_CASE("Pop Exception Test", "[inner"){
	AUDS<int> s;
	for(int i = 0; i < 100; i++){
		s.push(i);
	}

	for(int i = 0; i < 100; i++){
		s.pop();
	}
	CHECK_THROWS_WITH(s.pop(),"No elements are left to pop");
}

