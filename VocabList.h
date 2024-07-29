using namespace std;

struct VocabWord
{
    VocabWord *next;
    VocabWord *previous;
    string English;
    string German;
};
class VocabList

{
public:
    void Print();

    int Size();

    VocabWord *InitWord(string english, string german);

    void Append(VocabWord *toAppend);

    void Remove(VocabWord *toRemove);

    VocabList *SplitAt(int count);

    VocabList *JoinLists(VocabList *toJoin);

private:
    VocabWord *head;
    VocabWord *tail;
};