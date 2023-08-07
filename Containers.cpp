#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// https://cplusplus.com/reference/stl/


// -------------------------------------------------------------- Arrays
// https://cplusplus.com/reference/array/array/
// fixed sized
// int count_down[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

const int row_count = 2;
const int col_count = 3;

int grid[row_count][col_count] = {
    {0, 1, 2},
    {3, 4, 5},
};

const int depth_count = 4;

int cube[row_count][col_count][depth_count] = {
    {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}},
    {{12, 13, 14, 15}, {16, 17, 18, 19}, {20, 21, 22, 23}},
};

// -------------------------------------------------------------- Vectors
// https://cplusplus.com/reference/vector/vector/
// Variable sized array
std::vector<char> alphabet = {'a', 'b', 'c'};

// -------------------------------------------------------------- Stacks

// https://cplusplus.com/reference/stack/stack/
// LIFO
std::stack<int> plates;

// -------------------------------------------------------------- Queue
// https://cplusplus.com/reference/queue/queue/
// FIFO
std::queue<std::string> line;

// -------------------------------------------------------------- Set
// https://cplusplus.com/reference/set/set/
// https://cplusplus.com/reference/unordered_set/unordered_set/
std::unordered_set<int> primes({2, 3, 5, 7});

void removeAndPrint(int to_remove, std::unordered_set<int> &from_this) {
  int result = from_this.erase(to_remove);
  if (result == 1) {
    std::cout << "removed a " << to_remove << "\n";
  } else {
    std::cout << "there wasn't a " << to_remove << "\n";
  }
}

bool contains(int to_find, const std::unordered_set<int> &in_this) {
  int result = in_this.count(to_find);
  if (result != 0) {
    std::cout << "found a " << to_find << "\n";
    return true;
  } else {
    std::cout << "there wasn't a " << to_find << "\n";
    return false;
  }
}

// -------------------------------------------------------------- Map
// https://cplusplus.com/reference/unordered_map/
// https://cplusplus.com/reference/map/
// keys must be unique, but is hashed on BOTH key and value.
std::unordered_map<std::string, int> shopping_list({{"apples", 5},
                                                    {"eggs", 12}});

//---------------------------------------------------------------------- main()
int main(int argc, char *argv[]) {
  // Danger, this does not error out if put in too many args

// -------------------------------------------------------------- Arrays
  int test_count[5];
  for (int i = 0; i < argc; i++) {
    std::cout << "arg " << i << ": " << argv[i] << "\n";
    test_count[i] = i; // should have a max of 5
    std::cout << "overflow test " << i << ": " << test_count[i] << "\n";
  }

  std::cout << grid[1][2] << "\n";

  for (int i = 0; i < row_count; i++) {
    for (int j = 0; j < col_count; j++) {
      for (int k = 0; k < depth_count; k++) {
        std::cout << cube[i][j][k] << ", ";
      }
      std::cout << "\n";
    }
    std::cout << "\n";
  }

// -------------------------------------------------------------- Vector
  alphabet.push_back('d');
  alphabet.push_back('e');

  for (auto letter : alphabet) {
    std::cout << letter;
  }
  std::cout << "\n";
  char first = alphabet.front();
  std::cout << first << "\n";
  //actually has vs .capacity() which is allocated
  int size = alphabet.size(); 
  std::cout << size << "\n";
  for (auto letter : alphabet) {
    std::cout << letter;
  }
  std::cout << "\n";

// -------------------------------------------------------------- Stack
  plates.push(3);
  plates.push(8);
  plates.push(5);

  const int current_size = plates.size();
  for (int i = 0; i < current_size; i++) {
    int next = plates.top();
    plates.pop();
    std::cout << next << ' ';
  }
  std::cout << "\n";

// -------------------------------------------------------------- Queue
  line.push("George");
  line.push("Bonny");
  line.push("Linda");
  line.push("Dianne");

  const int line_size = line.size();
  for (int i = 0; i < line_size; i++) {
    std::string next = line.front();
    line.pop();
    std::cout << next << ' ';
  }
  std::cout << "\n";

// -------------------------------------------------------------- Set
  primes.insert(2);
  primes.insert(7);
  primes.insert(43);

  for (auto num : primes) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  removeAndPrint(2, primes);

  for (auto num : primes) {
    std::cout << num << " ";
  }

  removeAndPrint(2, primes);
  bool result = contains(5, primes);
  std::cout << result << "\n";

  std::cout << "\n";

  std::set<int> ordered({4, 2, 7, 1, 3});
  std::cout << "set: ";
  for (int n : ordered) {
    std::cout << n << " ";
  }

  // consider also my_set.rbegin() and my_set.rend()
  std::set<int, std::greater<int>> descending{4, 2, 7, 1, 3};
  std::cout << "descending set: ";
  for (int n : descending) {
    std::cout << n << " ";
  }

// -------------------------------------------------------------- Map
  std::cout << "\n";
  shopping_list.insert({"acorn squash", 1});    // does insert
  shopping_list.insert({"cashews, bag of", 1}); // does insert
  shopping_list.insert({"eggs", 24});           // does not update.
  shopping_list["eggs"] =
      2; // does update, but will also create if does not exits.
  // shopping_list.at("frozen peas"); //will be error, out of range.
  for (auto item : shopping_list) {
    std::cout << item.first << " " << item.second << "\n";
  }
  shopping_list.insert_or_assign("apples", 3);
  // shopping_list.
  for (auto item : shopping_list) {
    std::cout << item.first << " " << item.second << "\n";
  }
  // erase and count work similarly to set.
}