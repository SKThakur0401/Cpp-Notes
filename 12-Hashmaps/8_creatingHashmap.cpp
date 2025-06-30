// Here we are going to implement all the knowledge we gained from video-7 to video-12, of HASHMAPS.

// WE R GOING TO CREATE OUR OWN HASHMAPS!!!

// U CAN ALSO REVISE THEORY...IT'S IN FORM OF HAND-WRITTEN NOTES IN THE SCREENSHOTS FOLDER ON MAC,

#include<iostream>
using namespace std;

template <typename V>
class mapNode
{
    public:
    string key;
    V value;
    mapNode * next;
    mapNode(string key , V value)
    {
        this->key= key;
        this->value= value;
        next=NULL;
    }

    ~mapNode()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
    public:
    int numBuckets;
    int count;
    mapNode<V>**buckets;

    ourmap()
    {
        count=0;
        numBuckets=5;
        buckets= new mapNode<V>*[numBuckets];

        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i]=NULL;
        }
        
    }

    private:

    void rehash()
    {
        mapNode<V>** temp = buckets;
        buckets= new mapNode<V>*[2* numBuckets];

        for (int i = 0; i < 2* numBuckets; i++)
        {
            buckets[i]=NULL;
        }
        
        int oldBucketCount= numBuckets;
        numBuckets*=2;
        count=0;

        for (int i = 0; i < oldBucketCount; i++)
        {
            mapNode<V>* head= temp[i];

            while(head !=NULL)
            {
                insert(head->key,head->value);
                head=head->next;
            }
        }

        for (int i = 0; i < oldBucketCount; i++)
        {
            delete temp[i];
        }
        delete [] temp;
        
    }

    int getBucketIndex(string key)
    {
        int hashCode=0;
        int p=1;

        for (int i = key.length()-1; i >=0; i--)
        {
            hashCode+= (key[i])*p;

            hashCode=hashCode% numBuckets;
            p*=37;
            p=p% numBuckets;
        }
        return hashCode % numBuckets;

    }

    public:


    V remove(string key)
    {
        int bucketIndex= getBucketIndex(key);
        mapNode<V>* head= buckets[bucketIndex];
        mapNode<V>* prev= NULL;
        V retVal;
        while(head!=NULL)
        {
            if(head->key==key)
            {
                if(prev==NULL)
                {
                    retVal= head->value;
                    buckets[bucketIndex]= head->next;
                    head->next=NULL;
                    delete head;
                    count--;
                    return retVal;
                }

                prev->next=head->next;
                head->next=NULL;
                retVal= head->value;
                delete head;
                count--;
                return retVal;
            }

            prev=head;
            head=head->next;
        }

        return 0;
    }

    void insert(string key, V value)
    {
        int bucketIndex= getBucketIndex(key);

        mapNode<V>* head= buckets[bucketIndex];

        while(head!=NULL)
        {
            if(head->key== key)
            {
                head->value= value;
                return;
            }
            head=head->next;
        }
        head= buckets[bucketIndex];
        mapNode<V>* newNode= new mapNode<V>(key,value);
        newNode->next= head;
        buckets[bucketIndex]= newNode;
        count++;
        double loadFactor= (1.0* count)/numBuckets;

        if(loadFactor> 0.7) rehash();

    }

    int size()
    {
        return count;
    }

double getLoadFactor()
{
    return (1.0* count / numBuckets);
}


    V getValue(string key)
    {
        int bucketIndex= getBucketIndex(key);
        mapNode<V>* head= buckets[bucketIndex];
        while(head!=NULL)
        {
            if(head->key==key)
            {
                return head->value;
            }
            head=head->next;
        }
        return 0;
    }
};

int main(){

    ourmap<int> somu;

    somu.insert("saumya" ,20);
    cout<< somu.getLoadFactor() <<endl;

    somu.insert("sahaj" ,18);
    cout<< somu.getLoadFactor() <<endl;

    somu.insert("Harsh" ,19);
    cout<< somu.getLoadFactor() <<endl;

    somu.insert("Kunal" ,22);
    cout<< somu.getLoadFactor() <<endl;

    somu.insert("Eresh" ,19);
    cout<< somu.getLoadFactor() <<endl;

    somu.insert("suyo" ,22);
    cout<< somu.getLoadFactor() <<endl;


    somu.insert("sh" ,19);
    cout<< somu.getLoadFactor() <<endl;

    somu.insert("yo" ,22);
    cout<< somu.getLoadFactor() <<endl;

    somu.insert("shi" ,19);
    cout<< somu.getLoadFactor() <<endl;

    somu.insert("yoi" ,22);
    cout<< somu.getLoadFactor() <<endl;

    cout<< somu.size() <<endl;
    cout<< somu.getValue("Kunal") <<endl;
    somu.insert("Kunal" ,18);
    cout<< somu.getValue("Kunal") <<endl;
    cout<< somu.size() <<endl;


    // cout<<somu.size()<<endl;
    
    // cout<<somu.getValue("Harsh")<<endl;
    // cout<<somu.getValue("Kunal")<<endl;

    // int hage= somu.remove("Harsh");
    // hage=somu.remove("Saumya");
    // cout<< somu.size() <<endl;
    // cout<< hage <<endl;
    // cout<<somu.getValue("Harsh")<<endl;

    return 0;
}