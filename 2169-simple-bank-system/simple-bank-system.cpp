class Bank {
public:
    using ll = long long;
    vector<ll> bal;
    Bank(vector<long long>& balance) { bal = balance; }

    bool transfer(int ac1, int ac2, long long money) {
        if (ac1 > bal.size() || ac2 > bal.size() || bal[ac1 - 1] < money)
            return false;
        bal[ac1 - 1] -= money;
        bal[ac2 - 1] += money;
        return true;
    }

    bool deposit(int ac, long long money) {
        if (ac > bal.size())
            return false;
        bal[ac - 1] += money;
        return true;
    }

    bool withdraw(int ac, long long money) {
        if (ac > bal.size() || bal[ac - 1] < money)
            return false;
        bal[ac - 1] -= money;
        return true;
    }
};