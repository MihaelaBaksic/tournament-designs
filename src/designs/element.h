#ifndef H_ELEMENT
#define H_ELEMENT

class Element
{
    public:
        int value;
};


class StandardElement: private Element
{
    public:
        
};

class IndexedEelement: private Element
{
    public:
        int index;

       

};


#endif // !H_ELEMENT