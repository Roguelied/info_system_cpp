#include "Functions_Database.h"

void DataEntry(Data* (&d), int& n){
    Initials initials;
    Date date;
    Address address;
    Carriage carriage;

    cout << "Введите сколько записей надо сделать (элементов массива): ";
    cin >> n;

    d = new Data[n];

    for (int i = 0; i < n; i++){
        cout << "Введите ФИО: ";
        cin >> initials.surname >> initials.name >> initials.patrinymic;

        cout << "Введите Дату: ";
        cin >> date.day >> date.month >> date.year;

        cout << "Введите откуда-куда: ";
        cin >> address.fr_w >> address.to_w;

        cout << "Введите тип вагона: ";
        cin >> carriage.type;

        cout << "Введите цену билета: ";
        cin >> carriage.price;

        cout << "Введите ваш айди: ";
        cin >> carriage.id;

        cout << "Введите место в вагоне: ";
        cin >> carriage.place;

        d[i].DataEntry(initials, date, address, carriage);
        cout << "_______________________________\n";
    }
}

void Print(Data* d, int n){
    for(int i = 0; i < n; i++){
        cout << "Данные №" << i+1 << endl;

        d[i].Print();
        cout << "_______________________________\n";
    }
}

void DataChange(Data* d, int n){
    Initials initials;
    Date date;
    Address address;
    Carriage carriage;
    int _n;

    cout << "Введите номер нужного элемента (от 1 до " << n << "): ";
    cin >> _n;
    _n--;

    if (_n >= 0 && _n < n){
        cout << "Введите новую ФИО: ";
        cin >> initials.surname >> initials.name >> initials.patrinymic;

        cout << "Введите новую Дату: ";
        cin >> date.day >> date.month >> date.year;

        cout << "Введите новую откуда-куда: ";
        cin >> address.fr_w >> address.to_w;

        cout << "Введите новый тип вагона: ";
        cin >> carriage.type;

        cout << "Введите новую цену билета: ";
        cin >> carriage.price;

        cout << "Введите ваш новый айди: ";
        cin >> carriage.id;

        cout << "Введите новое место в вагоне: ";
        cin >> carriage.place;

        d[_n].DataEntry(initials, date, address, carriage);
    }
    else
        cout << "Номер введен не верно!" << endl;
}

void Copy(Data* d_n, Data* d_o, int n){
    for (int i = 0; i < n; i++){
        d_n[i] = d_o[i];
    }
}

void AddData(Data* (&d), int& n){
    Initials initials;
    Date date;
    Address address;
    Carriage carriage;
    Data* buf = new Data[n];
    int size = n, new_size = ++n;

    Copy(d, buf, size);

    d = new Data[new_size];

    Copy(d, buf, size);

    cout << "Введите новую ФИО: ";
    cin >> initials.surname >> initials.name >> initials.patrinymic;

    cout << "Введите новую Дату: ";
    cin >> date.day >> date.month >> date.year;

    cout << "Введите новую откуда-куда: ";
    cin >> address.fr_w >> address.to_w;

    cout << "Введите новый тип вагона: ";
    cin >> carriage.type;

    cout << "Введите новую цену билета: ";
    cin >> carriage.price;

    cout << "Введите ваш новый айди: ";
    cin >> carriage.id;

    cout << "Введите новое место в вагоне: ";
    cin >> carriage.place;

    d[size].DataEntry(initials, date, address, carriage);

    cout << "Данные добавлены!" << endl;

    delete[] buf;
}

void DeleteData(Data* (&d), int& n){
    int _n;
    Data* buf = new Data[n];

    cout << "Введите номер нужного элемента (от 1 до " << n << "): ";
    cin >> _n;
    _n--;

    if (_n>=0 && _n < n){
        Copy(buf, d, n);
        int q = 0;
        n--;

        d = new Data[n];

        for (int i = 0; i <= n; i++){
            if(i != _n){
                d[q] = buf[i];
                q++;
            }
        }

        cout << "Данные удалены!" << endl;
    }
    else
        cout << "Номер введен не верно!" << endl;
    delete[]buf;
}

void SortingData(Data* d, int n){
    Data buf;
    int numOfSorted = 0;

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (d[i].GetInitials().surname > d[i].GetInitials().surname){
                buf = d[i];
                d[i] = d[j];
                d[j] = buf;

                numOfSorted++;
            }
        }
        cout << "Данные отсортированы!\nКоличество сортировок: " << numOfSorted << endl;
    }

}

void SaveData(Data* d, int n, string fileName){
    ofstream record(fileName);

    if(record){
        record << n << endl;

        for(int i = 0; i < n; i++){
            record << d[i].GetInitials().surname << " " << d[i].GetInitials().name << " " << d[i].GetInitials().patrinymic << endl;
            record << d[i].GetDate().day << " " << d[i].GetDate().month << " " << d[i].GetDate().year << endl;
            record << d[i].GetAddress().fr_w << " " << d[i].GetAddress().to_w << endl;
            record << d[i].GetCarriage().place << " " << d[i].GetCarriage().id << " " << d[i].GetCarriage().price << " " << d[i].GetCarriage().type << endl;

            if (i < n - 1){
                record << endl;
            }
        }
    }
    else
        cout << "Ошибка открытия файла!" << endl;

    cout << "Данные сохранены в файл: " << fileName << endl;

    record.close();
}

