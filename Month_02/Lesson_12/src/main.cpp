#include <iostream>
#include "List.cpp"
#include "Sequence.cpp"

int main() {
    // Sequence container
    std::cout << "Sequence container" << std::endl;
    // 1. Create Sequence container to store objects of type int
    Sequence<int> sequence_container;
    // 2. Add 10 elements to container (0,1..9)
    std::cout << "Add 10 elements to Sequence container (0,1..9)" << std::endl;
    for (int i = 0; i < 10; ++i) {
        sequence_container.push_back(i);
    }
    // 3. Print container elements. Exp:  0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    std::cout << "Print container after adding 10 elements: ";
    std::cout << sequence_container << std::endl;
    // 4. Print container size. Exp: 10
    std::cout << "Container size: " << sequence_container.size() << std::endl;
    // 5. Delete 3rd, 5th and 7th element from container
    std::cout << "Delete 3rd (value = " << sequence_container[2] << "), ";
    std::cout << "5th (value = " << sequence_container[4] << ") ";
    std::cout << "and 7th (value = " << sequence_container[6] << ") elements from container" << std::endl;
    sequence_container.erase(2);
    sequence_container.erase(3);
    sequence_container.erase(4);
    // 6. Print container elements. Exp:  0, 1, 3, 5, 7, 8, 9
    std::cout << "Print container after erasing some elements: ";
    std::cout << sequence_container << std::endl;
    std::cout << "Container size: " << sequence_container.size() << std::endl;
    // 7. Add 10 to the beginning of container
    std::cout << "Add 10 to the beginning (index = 0) of container" << std::endl;
    sequence_container.insert(10, 0);
    // 8. Print container elements. Exp:  10, 0, 1, 3, 5, 7, 8, 9
    std::cout << "Print container after adding element to the beginning: ";
    std::cout << sequence_container << std::endl;
    std::cout << "Container size: " << sequence_container.size() << std::endl;
    // 9. Add 20 to the middle of container
    std::cout << "Add 20 to the middle (index = " << sequence_container.size()/2 << ") of container" << std::endl;
    sequence_container.insert(20, sequence_container.size()/2);
    // 10. Print container elements. Exp:  10, 0, 1, 3, 20, 5, 7, 8, 9
    std::cout << "Print container after adding element to the middle: ";
    std::cout << sequence_container << std::endl;
    std::cout << "Container size: " << sequence_container.size() << std::endl;
    // 11. Add 30 to the end of container
    std::cout << "Add 30 to the end (index = " << sequence_container.size() << ") of container" << std::endl;
    sequence_container.insert(30, sequence_container.size());
    // 12. Print container elements. Exp:  10, 0, 1, 3, 20, 5, 7, 8, 9, 30
    std::cout << "Print container after adding element to the end: ";
    std::cout << sequence_container << std::endl;
    std::cout << "Container size: " << sequence_container.size() << std::endl;

    // 13. Insert at index out of range
    std::cout << "Add 40 beyond the end of container" << std::endl;
    sequence_container.insert(40, sequence_container.size() + 5);
    std::cout << "Print container after adding element beyond the end: ";
    std::cout << sequence_container << std::endl;
    std::cout << "Container size: " << sequence_container.size() << std::endl;

    std::cout << std::endl<< std::endl;

    // List container
    std::cout << "List container" << std::endl;
    // 1. Create List container to store objects of type int
    List<int> list_container;
    // 2. Add 10 elements to container (0,1..9)
    std::cout << "Add 10 elements to List container (0,1..9)" << std::endl;
    for (int i = 0; i < 10; ++i) {
        list_container.push_back(i);
    }
    // 3. Print container elements. Exp:  0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    std::cout << "Print container after adding 10 elements: ";
    std::cout << list_container << std::endl;
    // 4. Print container size. Exp: 10
    std::cout << "Container size: " << list_container.size() << std::endl;
    //5. Delete 3rd, 5th and 7th element from container
    std::cout << "Delete 3rd (value = " << list_container[2] << "), ";
    std::cout << "5th (value = " << list_container[4] << ") ";
    std::cout << "and 7th (value = " << list_container[6] << ") elements from container" << std::endl;
    list_container.erase(2);
    list_container.erase(3);
    list_container.erase(4);
    //6. Print container elements. Exp:  0, 1, 3, 5, 7, 8, 9
    std::cout << "Print container after erasing some elements: ";
    std::cout << list_container << std::endl;
    std::cout << "Container size: " << list_container.size() << std::endl;
    // 7. Add 10 to the beginning of container
    std::cout << "Add 10 to the beginning (index = 0) of container" << std::endl;
    list_container.insert(10, 0);
    // 8. Print container elements. Exp:  10, 0, 1, 3, 5, 7, 8, 9
    std::cout << "Print container after adding element to the beginning: ";
    std::cout << list_container << std::endl;
    std::cout << "Container size: " << list_container.size() << std::endl;
    // 9. Add 20 to the middle of container
    std::cout << "Add 20 to the middle (index = " << list_container.size()/2 << ") of container" << std::endl;
    list_container.insert(20, list_container.size()/2);
    // 10. Print container elements. Exp:  10, 0, 1, 3, 20, 5, 7, 8, 9
    std::cout << "Print container after adding element to the middle: ";
    std::cout << list_container << std::endl;
    std::cout << "Container size: " << list_container.size() << std::endl;
    // 11. Add 30 to the end of container
    std::cout << "Add 30 to the end (index = " << list_container.size() << ") of container" << std::endl;
    list_container.insert(30, list_container.size());
    // 12. Print container elements. Exp:  10, 0, 1, 3, 20, 5, 7, 8, 9, 30
    std::cout << "Print container after adding element to the end: ";
    std::cout << list_container << std::endl;
    std::cout << "Container size: " << list_container.size() << std::endl;

    return 0;
}