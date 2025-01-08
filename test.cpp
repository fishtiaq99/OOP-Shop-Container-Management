#include "pch.h"

// QUESTION 1
// add_Container TEST
TEST(Shop, add_Container) {
	Shop obj;
	char name1[5] = "PENS";
	char name2[6] = "RULER";
	char name3[7] = "BINDER";
	obj.add_Container(name1, 12);
	obj.add_Container(name2, 7);
	obj.add_Container(name3, 20);
	char* test = obj.start->link->name;
	EXPECT_EQ(0, strcmp(name2, test));
	EXPECT_EQ(NULL, (obj.start->link->link->link));
}
//CopyConstructor
TEST(Shop, copyConstructor) {

	Shop obj;
	char name1[5] = "PENS";
	char name2[6] = "RULER";
	char name3[7] = "BINDER";
	obj.add_Container(name1, 12);
	obj.add_Container(name2, 7);
	obj.add_Container(name3, 20);

	Shop obj2(obj);

	obj.update_name_at_containerNumber(7, "STAPLER");

	char* test = obj2.start->link->name;
	EXPECT_EQ(0, strcmp(name2, test));
	EXPECT_EQ(NULL, (obj2.start->link->link->link));
}
// PRINT_SHOP TEST
TEST(Shop, print_Shop) {
	Shop obj;

	testing::internal::CaptureStdout();
	obj.print_Shop();
	std::string output0 = testing::internal::GetCapturedStdout();
	std::string answer0 = "";

	EXPECT_EQ(1, output0 == answer0);

	char name1[5] = "PENS";
	char name2[6] = "RULER";
	char name3[7] = "BINDER";
	obj.add_Container(name1, 12);
	obj.add_Container(name2, 7);
	obj.add_Container(name3, 20);

	testing::internal::CaptureStdout();
	obj.print_Shop();
	std::string output = testing::internal::GetCapturedStdout();
	std::string answer = "PENS-12\nRULER-7\nBINDER-20\n";

	EXPECT_EQ(1, output == answer);
}
// DELETE_CHAIN TEST
TEST(Shop, delete_Chain) {
	Shop obj;
	char name1[5] = "PENS";
	obj.add_Container(name1, 12);
	obj.delete_Chain(12);
	EXPECT_EQ(NULL, (obj.start));
	char name2[6] = "RULER";
	char name3[7] = "BINDER";
	obj.add_Container(name1, 12);
	obj.add_Container(name2, 7);
	obj.add_Container(name3, 20);
	obj.delete_Chain(7);
	EXPECT_EQ(0, strcmp(name3, (obj.start->link->name)));
	EXPECT_EQ(NULL, obj.start->link->link);
	char name4[5] = "TAPE";
	obj.add_Container(name4, 5);
	EXPECT_EQ(0, strcmp(name4, (obj.start->link->link->name)));

}
// SORT_CHAIN TEST
TEST(Shop, Sort_Chain) {
	Shop obj;
	char name1[5] = "PENS";
	char name2[6] = "RULER";
	char name3[7] = "BINDER";
	obj.add_Container(name1, 12);
	obj.add_Container(name2, 7);
	obj.add_Container(name3, 20);
	obj.Sort_Chain();

	EXPECT_EQ(0, strcmp(name2, (obj.start->name)));
	EXPECT_EQ(0, strcmp(name1, (obj.start->link->name)));
	EXPECT_EQ(0, strcmp(name3, (obj.start->link->link->name)));

	char name4[5] = "TAPE";
	obj.add_Container(name4, 5);

	obj.Sort_Chain();
	EXPECT_EQ(0, strcmp(name2, (obj.start->link->name)));
	EXPECT_EQ(0, strcmp(name1, (obj.start->link->link->name)));
	EXPECT_EQ(0, strcmp(name3, (obj.start->link->link->link->name)));
	EXPECT_EQ(0, strcmp(name4, (obj.start->name)));

}
TEST(Shop, update_name_at_containernumber) {
	Shop obj;
	char name1[5] = "PENS";
	char name2[6] = "RULER";
	char name3[7] = "BINDER";
	obj.add_Container(name1, 12);
	obj.add_Container(name2, 7);
	obj.add_Container(name3, 20);

	obj.update_name_at_containerNumber(7, "PROTRACTOR");
	obj.update_name_at_containerNumber(12, "HIGHLIGHTER");
	obj.update_name_at_containerNumber(20, "STAPLER");

	EXPECT_EQ(0, strcmp(obj.start->name, "HIGHLIGHTER"));
	EXPECT_EQ(0, strcmp(obj.start->link->name, "PROTRACTOR"));
	EXPECT_EQ(0, strcmp(obj.start->link->link->name, "STAPLER"));

}
TEST(Shop, remove_Duplicate) {
	Shop obj;
	char name1[5] = "PENS";
	char name2[6] = "RULER";
	char name3[7] = "BINDER";
	obj.add_Container(name1, 12);
	obj.add_Container(name2, 7);
	obj.add_Container(name3, 20);
	obj.add_Container(name3, 20);
	obj.add_Container(name1, 12);
	obj.remove_Duplicate();

	char* test = obj.start->link->name;
	EXPECT_EQ(0, strcmp(name2, test));
	EXPECT_EQ(NULL, (obj.start->link->link->link));

	Shop obj1;
	obj1.add_Container(name1, 12);
	obj1.add_Container(name1, 12);
	obj1.add_Container(name1, 12);
	obj1.remove_Duplicate();
	EXPECT_EQ(0, strcmp(name1, obj1.start->name));
	EXPECT_EQ(NULL, (obj1.start->link));
}
// FIND_CONTAINER TEST
TEST(Shop, findContainer) {
	Shop obj;
	char name1[5] = "PENS";
	char name2[6] = "RULER";
	char name3[7] = "BINDER";
	obj.add_Container(name1, 12);
	obj.add_Container(name2, 7);
	obj.add_Container(name2, 7);
	obj.add_Container(name3, 20);

	testing::internal::CaptureStdout();
	obj.findContainer(7);
	std::string output = testing::internal::GetCapturedStdout();
	std::string answer = "RULER\n";

	EXPECT_EQ(1, output == answer);

	testing::internal::CaptureStdout();
	obj.findContainer(8);
	std::string output2 = testing::internal::GetCapturedStdout();
	std::string answer2 = "";

	EXPECT_EQ(1, output2 == answer2);

}
//FIND_CONTAINER RANGE TEST
TEST(Shop, findContainer2) {

	Shop obj;
	char name1[5] = "PENS";
	char name2[6] = "RULER";
	char name3[7] = "BINDER";
	char name4[8] = "STAPLER";
	char name5[7] = "ERASER";
	obj.add_Container(name1, 12);
	obj.add_Container(name2, 7);
	obj.add_Container(name3, 20);
	obj.add_Container(name4, 30);
	obj.add_Container(name5, 24);

	testing::internal::CaptureStdout();
	obj.findContainer(12, 25); //12 and 25 are both Included in the Range
	std::string output = testing::internal::GetCapturedStdout();
	std::string answer = "PENS\nBINDER\nERASER\n";

	EXPECT_EQ(1, output == answer);

}