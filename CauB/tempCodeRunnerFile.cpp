friend istream &operator>>(istream &is, DaThuc &dt)
    {
        int n;
        // cout << "Nhap bac cua da thuc: ";
        is >> n;
        T heso, somu;
        for (int i = 0; i < n; i++)
        {
            // cout << "Nhap he so va so mu: ";
            is >> heso >> somu;
            dt.insert(heso, somu);
        }
        return is;
    }
    friend ostream &operator<<(ostream &os, const DaThuc &dt)
    {
        node<T> *h = dt.head->getNext();
        // cout << "Da thuc ban vua nhap la:\n";
        while (h != dt.trailer)
        {
            os << h->getHeSo() << "x^" << h->getSoMu();
            if (h->getNext() != dt.trailer && h->getNext()->getHeSo() > 0)
                os << " + ";
            else
                cout << " ";
            h = h->getNext();
        }
        cout << "\n";
        return os;
    }
    void readFromFile(const string& filename){
        ifstream infile(filename);
        if(infile.is_open()){
            int n, somu;
            T heso;
            infile >> n;
            for(int i = 0; i < n; i++){
                infile >> heso >> somu;
                insert(heso, somu);
            }
            cout << "Mo file thanh cong!"<< endl;
        }
        else{
            cout << "Mo file that bai!" << endl;
        }
        infile.close();
    }
    void writeToFile(const string& filename){
        ofstream outfile(filename, ios::app);
        if (outfile.is_open()) {
            node<T>* h = head->getNext();
            while (h != trailer) {
                outfile << h->getHeSo() << "x^" << h->getSoMu();
                if (h->getNext() != trailer && h->getNext()->getHeSo() > 0) outfile << " + ";
                h = h->getNext();
            }
            outfile << endl;
            outfile.close();
        } else {
            cout << "Khong the mo file" << endl;
        }
    }