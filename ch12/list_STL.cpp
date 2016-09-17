//����������Professional C++ ��
//��12���������������� list����ز���

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
        auto iterLastB = --(bWords.cend()); //cbegin��cendֻ���������ֻ������
        list<string>::iterator it;
        for (it = dictionary.begin(); it != dictionary.end(); ++it) {
            if (*it > *iterLastB)           //forѭ��������Ѱ�Һ��ʵĲ���λ��
                break;
        }

        dictionary.splice(it, bWords); //������dictionary��it����������bWords
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
    for (auto& lst : courseStudents) { //ÿһ��lst����list<string>
        allStudents.insert(allStudents.end(), lst.begin(), lst.end());
    } //������allStudents��ĩβ����lst

    allStudents.sort(); //����
    allStudents.unique(); //Ψһ��

    for (auto& str : droppedStudents) { //���ڷ�Χ��forѭ��
        allStudents.remove(str); //������allStudents��ɾ��str
    }

//    ������forѭ���ȼۣ��������ӵĴ���ʾ��
//    for (list<string>::const_iterator it = droppedStudents.begin();
//         it != droppedStudents.end(); ++it) {
//        allStudents.remove(*it);
//    }

    return allStudents;
}
