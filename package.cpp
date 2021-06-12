#include <iostream>

using namespace std;

class Package{

    private:
        float weight;
        float cost;
    
    public:
        Package(float weight, float cost){
            setNumber(weight, cost);
        }

        void setNumber(float weight, float cost){
            this->weight = weight;
            this->cost = cost;
        }

        float getWeight(){
            return this->weight;
        }

        float getCost(){
            return this->cost;
        }

        float calculateCost(){
            return getWeight()*getCost();
        }
};

class TwoDayPackage : private Package{

    private:
        float fee;

    public:
        TwoDayPackage(float weight, float cost, float fee) : Package(weight, cost){
            setFee(fee);
        } 

        void setFee(float fee){
            this->fee = fee;
        }

        float getFee(){
            return this->fee;
        }

        float calculateCost(){
            return Package::calculateCost() + getFee();
        }
};

class OvernightPackage : public Package{
    private: 
        float fee;
    
    public:
        OvernightPackage(float weight, float cost, float fee) : Package(weight, cost){
            setFee(fee);
        };

        void setFee(float fee){
            this->fee = fee;
        }

        float getFee(){
            return this->fee;
        }

        float calculateCost(){
            float weight;
            float totalCost;

            weight = (Package::getWeight()) * (getFee());
            totalCost = Package::calculateCost() + weight;

            return totalCost;
        }
};


int main(){

    float a, b, c, d;

    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    Package pack(a,b);
    printf("\n%.2f", pack.calculateCost());

    TwoDayPackage packTwo(a,b,c);
    printf("\n%.2f", packTwo.calculateCost());
    
    OvernightPackage packNight(a,b,d);
    printf("\n%.2f", packNight.calculateCost());

}