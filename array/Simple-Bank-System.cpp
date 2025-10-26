#define ll long long

class Bank {
private:
    vector<ll> v;

public:
    Bank(vector<ll>& v) { this->v = v; }

    bool transfer(int acc1, int acc2, ll money) {
        if (acc1 <= 0 || acc2 <= 0 || acc1 > v.size() || acc2 > v.size())
            return false;
        if (money < 0 || v[acc1 - 1] < money)
            return false;
        v[acc1 - 1] -= money;
        v[acc2 - 1] += money;
        return true;
    }

    bool deposit(int acc, ll money) {
        if (acc <= 0 || acc > v.size() || money < 0)
            return false;
        v[acc - 1] += money;
        return true;
    }

    bool withdraw(int acc, ll money) {
        if (acc <= 0 || acc > v.size() || money < 0 || v[acc - 1] < money)
            return false;
        v[acc - 1] -= money;
        return true;
    }
};
