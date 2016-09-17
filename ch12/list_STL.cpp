//本例来自于Professional C++ 中
//第12章理解容器与迭代器 list的相关操作

#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    list<string> dictionary, bWords;
    dictionary.push_back("aardvark");
    dictionary.push_back("ambulance");
    dictionary.push_back("canticle");
    dictionary.push_back("consumerism");

    bWords.push_back("bathos");
    bWords.push_back("balderdash");

    if (bWords.size() > 0) {
        auto iterLastB = --(bWords.cend()); //cbegin和cend只赋予迭代器只读功能
        list<string>::iterator it;
        for (it = dictionary.begin(); it != dictionary.end(); ++it) {
            if (*it > *iterLastB)           //for循环作用是寻找合适的插入位置
                break;
        }

        dictionary.splice(it, bWords); //在链表dictionary的it处插入链表bWords
    }

    for (auto it = dictionary.cbegin(); it != dictionary.cend(); ++ it) {
        cout << *it << endl;
    }
    return 0;
}


list<string> getTotalEnrollment (const vector<list<string>>& courseStudents,
                                 const list<string>& droppedStudents)
{
    list<string> allStudents;
    for (auto& lst : courseStudents) { //每一个lst都是list<string>
        allStudents.insert(allStudents.end(), lst.begin(), lst.end());
    } //在链表allStudents的末尾插入lst

    allStudents.sort(); //排序
    allStudents.unique(); //唯一化

    for (auto& str : droppedStudents) { //基于范围的for循环
        allStudents.remove(str); //在链表allStudents中删除str
    }

//    与上面for循环等价，但更复杂的代码示例
//    for (list<string>::const_iterator it = droppedStudents.begin();
//         it != droppedStudents.end(); ++it) {
//        allStudents.remove(*it);
//    }

    return allStudents;
}
