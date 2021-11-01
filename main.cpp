#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<array>
#include<cctype>
#include<vector>
#include<stdexcept>


using namespace std;

typedef struct matric SM;
struct matric
{
    string name;
    int row = 0;
    int col = 0;
    string ** arr;
    //array< array<double, 0>, 0> arr;
};


void menu()
{
    cout 
    << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl
    << "1_ for add matrix, type [add matrix] *<name-matrix> *<row> *<column>" << endl
    << "2_ for To find out if the matrix is diagonal, type [is_diagonal] *<name-matrix>" << endl
    << "3_ for To find out if the matrix is upper triangular, type [is_upper_triangular] *<name-matrix>" << endl
    << "4_ for To find out if the matrix is lower triangular, type[is_lower_triangular] *<name-matrix>" << endl
    << "5_ for To find out if the matrix is triangular(general), type [is_triangular] *<name-matrix>" << endl
    << "6_ fot To find out if the matrix is normal_symmetric, type [is_normal_symmetric] *<name-matrix>" << endl
    << "7_ fot to find out if the matrix is skew_symmetric, type [is_skew_symmetric] *<name-matrix>" << endl
    << "8_ fot To find out if the matrix is symmetric(general), type [is_symmetric] *<name-matrix>" << endl
    << "9_ for inverse matrix, type [inverse] *<old-name-matrix> <new-name-matrix>" << endl
    << "10_ for print name and matrix members, type [show] *<name-matrix>" << endl
    << "11_ for delete matrix, type [delete] *<name-matrix>" << endl
    << "12_ for To edit a matrix member, type [change] *<row> *<col> *<name-matrix>" << endl
    << "13_ for recive menu, type [help]" << endl
    << "14_ for close app, type [exit]" << endl
    << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    
}

SM add(string name, int row, int col, string temp)
{
    SM tempsave;

    tempsave.name = name;    
    tempsave.row = row;
    tempsave.col = col;

    tempsave.arr = new string*[row]();//crate 1d array

    for (size_t i = 0; i < row; i++)
    {
        tempsave.arr[i] = new string[col];//crate 2d array
    }

    if (temp.empty())//get member matrix
    {
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                cout << "meghdar khane [" << i+1 << "][" << j+1 << "] ra vared konid--->";
                cin >> tempsave.arr[i][j];
            }
            
        }
        
    }
    else //get by initial list
    {
        string arre[row*col];//save digit
        int k = 0;
        int point = 0;
        for (size_t i = 0; i < temp.size(); i++)
        {
            point = 0;
            string co = "";//NULL
            int j = 1;
            if (isdigit(temp[i]) || isalpha(temp[i]) || temp[i] == '-')//get member matrix
            {
                co = temp[i];
                while ((isdigit(temp[i+j]) || isalpha(temp[i+j]) || temp[i+j] == '.') && i+j < temp.size())
                {
                    point++;
                    co+= temp[i+j];
                    j++;
                }
                arre[k] = co;
                k++;
            }
            i += point;
        }

        k = 0;

        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                tempsave.arr[i][j] = arre[k];
                k++;
            }
            
        }
        
        
    }
    return tempsave;
}

bool diagonal(vector<SM> save, int len)
{
    bool diago = true;
    
    for (size_t i = 0; i < save[len].row; i++)
    {
        for (size_t j = 0; j < save[len].col; j++)
        {
            if (i != j)
            {
                if (save[len].arr[i][j] != "0")                                               
                {
                    diago = false;
                    break;
                }
                
            }
            
        }
        if (!(diago))
        {
            break;
        }
    }
    return diago;
}

bool up_triangular(vector<SM> save, int len)
{
    bool dw_triang = true;//for bala mosalasi bodane

    for (size_t i = 0; i < save[len].row; i++)
    {
        for (size_t j = 0; j < save[len].col; j++)
        {
            if (j > i)
            {
                if (save[len].arr[i][j] != "0")                                                     
                {
                    dw_triang = false;
                    break;
                }
                
            }
            
        }
    }
    
    return dw_triang;
}

bool dw_triangular(vector<SM> save, int len)
{
    bool up_triang = true;//for pain mosalasi bodane haa

    for (size_t i = 0; i < save[len].row; i++)
    {
        for (size_t j = 0; j < save[len].col; j++)
        {
            if (i > j)
            {
                if (save[len].arr[i][j] != "0")                                                  
                {
                    up_triang = false;
                    break;
                }
                
            }
            
        }
    }

    return up_triang;
}

bool normal_symmetric(vector<SM> save, int len)
{
    bool symmet = true;

    for (size_t i = 0; i < save[len].row; i++)
    {
        for (size_t j = 0; j < save[len].col; j++)
        {
            if (i != j && j > i)//in shart i != j ro fekr nakonam lazem bashe
            {
                if (save[len].arr[i][j] != save[len].arr[j][i])
                {
                    symmet = false;
                    break;
                }
                
            }
            
        }
        if (!symmet)
        {
            break;
        } 
    }
    
    return symmet;
}

bool skew_symmetric(vector<SM> save, int len)
{
    string neg = "-";
    bool symmet = true;

    for (size_t i = 0; i < save[len].row; i++)
    {
        for (size_t j = 0; j < save[len].col; j++)
        {
            if (i != j && j > i)
            {
                if (save[len].arr[i][j] == (save[len].arr[j][i]));
                {
                    //cout << "miad injaaa?" << endl;
                    //cout << save[len].arr[i][j] << "==" << save[len].arr[j][i];//nmifahmam chi mige
                    //getchar();
                    symmet = false;
                    //break;
                }
                if (save[len].arr[i][j] == (neg + save[len].arr[j][i]) ||
                         (neg + save[len].arr[i][j]) == save[len].arr[j][i])
                {
                    continue;
                }
                else
                {
                    symmet = false;
                    break;
                } 
                
            }
            
        }
        if (!symmet)
        {
            break;
        } 
    }
    
    return symmet;
}

void inverse(vector<SM> &save, int len, string new_name)
{
    if (new_name.empty() || new_name == "\n")//chek new name karbar dade ya na
    {
        string temp;

        for (size_t i = 0; i < save[len].row; i++)
        {
            for (size_t j = 0; j < save[len].col; j++)
            {
                if (i != j && j > i)
                {
                    temp = save[len].arr[i][j];
                    save[len].arr[i][j] = save[len].arr[j][i];
                    save[len].arr[j][i] = temp;
                }
                
            }
            
        }
        
    }
    else
    {
        SM tempsave;
        tempsave.name = new_name;
        tempsave.row = save[len].row;
        tempsave.col = save[len].col;

        tempsave.arr = new string*[tempsave.row]();
        for (size_t i = 0; i < tempsave.row; i++)
        {
            tempsave.arr[i] = new string[tempsave.col]();
        }
        

        for (size_t i = 0; i < save[len].row; i++)
        {
            for (size_t j = 0; j < save[len].col; j++)
            {
                if (i == j)
                {
                    tempsave.arr[i][j] = save[len].arr[i][j];
                }
                else
                {
                    tempsave.arr[i][j] = save[len].arr[j][i];
                }
            }
            
        }
        save.push_back(tempsave);
    }
}

void show(vector<SM> save, int len)
{
    cout << "name matrix is :" << save[len].name << "...." << endl;

    for (size_t i = 0; i < save[len].row; i++)//ja in 2ta for ye function benevis
    {
        for (size_t j = 0; j < save[len].col; j++)
        {
            cout << save[len].arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void del(vector<SM> save, int len)
{
    save[len].name = "-1";

    for (size_t i = 0; i < save[len].row; i++)
    {
        delete [] save[len].arr[i];
    }
    delete [] save[len].arr;
}

void change(vector<SM> &save, int len)
{
    int crow;
    cin >> crow;
    
    int ccol;
    cin >> ccol;

    if (crow < 0 || crow > save[len].row || ccol < 0 || ccol > save[len].col)
    {
        cout << "adad dade shode na motabar mibashand!!!!" << endl;
        return;
    }
    
    
    string number;
    cin >> number;
    
    save[len].arr[crow-1][ccol-1] = number;//-1 because we start 0 for row and column
}

int main()
{
    vector <SM> save;
    cout << "welcome to program..." << endl;
    string get;
    menu();

    getline(cin, get, ' ');//get function 
    transform(get.begin(), get.end(), get.begin(), ::tolower); //lower case string
    if (get == "add")
    {
        string temp;
        getline(cin, temp, ' ');
        get += " " + temp;
        transform(get.begin(), get.end(), get.begin(), ::tolower);
    }
    
    int row = 0;
    int col = 0;//for array

    while (get != "exit")
    {
        if (get == "add matrix")
        {
            bool flag = false;
            string temp;
            getline(cin, temp);
            int i = 0;

            string name;
            while (!(isspace(temp[i])))//get name matrix
            {
                name += temp[i];
                i++;
            }
            i++;//jump on space

            string srow;
            while (!(isspace(temp[i])))//get row matrix
            {
                srow += temp[i];
                i++;
                if (i > temp.size())
                {
                    break;
                }
                
            }
            row = stoi(srow);
            i++;//jump on space

            string scol;
            if (i < temp.size() && isdigit(temp[i]))//get col matrix
            {
                if (temp[i] != NULL)//ye warning vase in null dare ama goya jedi nist
                {
                    while (!(isspace(temp[i])))
                    {
                        scol += temp[i];
                        i++;
                        if (i > temp.size())
                        {
                            break;
                        }
                        
                    }
                    col = stoi(scol);
                    i++;//jump on space
                }
                else
                {
                    col = row;
                    flag = true;
                }
            }
            else
            {
                col = row;
                flag = true;
            }
            
            string templist;//for initial list
            if (i < temp.size())
            {
                while (!(isspace(temp[i])))//get initial list
                {
                    templist += temp[i];
                    i++;
                    if (i > temp.size())
                    {
                        break;
                    }
                    
                }
                
            }         
            
            save.push_back(add(name, row, col, templist));
            /*cout << "--------------" << endl;
            
            for (size_t i = 0; i < row; i++)
            {
                for (size_t j = 0; j < col; j++)
                {
                    //ye cast soski baraye dorost neshon dadan adad ke dar asl char hast
                    cout << save[count].arr[i][j] << "\t";
                }
                cout << endl;
            }
            count++;*/
            
        }
        else if (get == "is_diagonal" || get == "is-diagonal")
        {
            string name_mat;
            getline(cin, name_mat);
            bool diago = false;
            for (size_t i = 0; i < save.size(); i++)
            {
                if (save[i].name == name_mat)
                {
                    if (save[i].row != save[i].col)
                    {
                        cout << "matrix morabai nist !!!!" << endl;
                        //mitoni yedone exception ham throw koni!!!
                        break;
                    }
                    
                    diago = diagonal(save, i);
                    break;
                }
                
            }

            if (diago == true)
            {
                cout << "Yes is a diagonal" << endl;
            }
            else
            {
                cout << "No is not diagonal" << endl;
            }
            
        }
        else if (get == "is_upper_triangular" || get == "is-upper-triangular" ||
                 get == "is-upper_triangular" || get =="is_upper-triangular")
        {
            string name_mat;
            getline(cin, name_mat);

            bool triang = false;
            for (size_t i = 0; i < save.size(); i++)
            {
                if (save[i].name == name_mat)
                {
                    if (save[i].row != save[i].col)
                    {
                        cout << "matrix morabai nist !!!!" << endl;
                        //mitoni yedone exception ham throw koni!!!
                        break;
                    }

                    triang = up_triangular(save, i);
                    break;
                }
                
            }

            if (triang)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        
        }
        else if (get == "is_lower_triangular" || get == "is-lower-triangular" ||
                 get == "is-lower_triangular" || get =="is_lower-triangular")
        {
            string name_mat;
            getline(cin, name_mat);

            bool triang = false;
            for (size_t i = 0; i < save.size(); i++)
            {
                if (save[i].name == name_mat)
                {
                    if (save[i].row != save[i].col)
                    {
                        cout << "matrix morabai nist !!!!" << endl;
                        //mitoni yedone exception ham throw koni!!!
                        break;
                    }

                    triang = dw_triangular(save, i);
                    break;
                }
                
            }

            if (triang)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else if (get == "is_triangular" || get == "is-triangular")
        {
            string name_mat;
            getline(cin, name_mat);

            bool up_triang = false;
            bool dw_triang = false;

            for (size_t i = 0; i < save.size(); i++)
            {
                if (save[i].name == name_mat)
                {
                    if (save[i].row != save[i].col)
                    {
                        cout << "matrix morabai nist !!!!" << endl;
                        //mitoni yedone exception ham throw koni!!!
                        break;
                    }

                    up_triang = up_triangular(save, i);
                    dw_triang = dw_triangular(save, i);
                    break;
                }
                
            }
            if (up_triang)
            {
                cout << "matrix[" << name_mat << "]pain mosalasi ast" << endl;
            }
            if (dw_triang)
            {
                cout << "matrix[" << name_mat << "]bala mosalasi ast" << endl;
            }
            if (up_triang && dw_triang)
            {
                cout << "matrix[" << name_mat << "]bala va pain mosalasi ast" << endl;
            }
            else
            {
                cout << "matrix[" << name_mat << "]bala va pain mosalasi nist" << endl;
            }
            
        }
        else if (get == "is_identity" || get == "is-identity")
        {
            string name_mat;
            getline(cin, name_mat);
            bool diago = false;
            int len = 0;
            for (size_t i = 0; i < save.size(); i++)
            {
                if (save[i].name == name_mat)
                {
                    len = i;
                    if (save[i].row != save[i].col)
                    {
                        cout << "matrix morabai nist !!!!" << endl;
                        //mitoni yedone exception ham throw koni!!!
                        break;
                    }
                    
                    diago = diagonal(save, i);
                    break;
                }
                
            }

            bool ident = true;
            if (diago)//bebin misarfe ino bokoni to ye function
            {
                for (size_t i = 0; i < save[len].row; i++)
                {
                    for (size_t j = 0; j < save[len].col; j++)
                    {
                        if (i == j)
                        {
                            if (save[len].arr[i][j] != "1")
                            {
                                ident = false;
                                break;
                            }
                            
                        }
                        
                    }
                    if (!(ident))
                    {
                        break;
                    }
                    
                }
                
            }
            
            if (ident)
            {
                cout << "matrix[" << name_mat << "] hamani ast" << endl;
            }
            else
            {
                cout << "matrix[" << name_mat << "] hamani nist" << endl;
            }
            
        }
        else if (get == "is_normal_symmetric" || get == "is-normal-symmetric"||
                 get == "is-normal_symmetric" || get == "is_normal-symmetric")
        {
            string name_mat;
            getline(cin, name_mat);

            bool symmet = false;
            for (size_t i = 0; i < save.size(); i++)
            {
                if (save[i].name == name_mat)
                {
                    if (save[i].row != save[i].col)
                    {
                        cout << "matrix morabai nist !!!!" << endl;
                        //mitoni yedone exception ham throw koni!!!
                        break;
                    }

                    symmet = normal_symmetric(save, i);
                    break;
                }
                
            }

            if (symmet)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            
        }
        else if (get == "is_skew_symmetric" || get == "is-skew-symmetric" ||
                 get == "is-skew_symmetric" || get == "is_skew-symmetric")
        {
            string name_mat;
            getline(cin, name_mat);

            bool symmet = false;
            for (size_t i = 0; i < save.size(); i++)
            {
                if (save[i].name == name_mat)
                {
                    if (save[i].row != save[i].col)
                    {
                        cout << "matrix morabai nist !!!!" << endl;
                        //mitoni yedone exception ham throw koni!!!
                        break;
                    }

                    symmet = skew_symmetric(save, i);
                    break;
                }
                
            }

            if (symmet)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else if (get == "is_symmetric" || get == "is-symmetric")
        {
            string name_mat;
            getline(cin, name_mat);

            bool symmet = false;
            bool type = false;//yani skew nist be sorat pish farz
            for (size_t i = 0; i < save.size(); i++)
            {
                if (save[i].name == name_mat)
                {
                    if (save[i].row != save[i].col)
                    {
                        cout << "matrix morabai nist !!!!" << endl;
                        //mitoni yedone exception ham throw koni!!!
                        break;
                    }

                    symmet = normal_symmetric(save, i);
                    type = skew_symmetric(save, i);
                    break;
                }
                
            }

            if (type)
            {
                cout << "matrix[" << name_mat << "] is :skew_symmetric" << endl;
            }
            if (symmet)
            {
                cout << "matrix[" << name_mat << "] is :normal_symmetric" << endl;
            }
            if (!(symmet) && !(type))
            {
                cout << "matrix[" << name_mat << "] is :Not symmetric" << endl;
            }
        }
        else if (get == "inverse")
        {
            string temp;
            getline(cin, temp);

            string name_mat;
            string new_name;
            size_t i = 0;

            while (!(isspace(temp[i])))//get old name
            {
                name_mat += temp[i];
                i++;
                if (temp[i] == '\n' || temp[i] == ' ' || i >= temp.size())
                {
                    break;
                }
            }
            
            i++;//for jump space

            if (i < temp.size())
            {
                while (!(isspace(temp.at(i))))//get new name
                {
                    new_name += temp[i];
                    i++;
                    if (temp[i] == '\n' || temp[i] == ' ' || i >= temp.size())
                    {
                        break;
                    }
                }
            }
            
            
            
            for (size_t i = 0; i < save.size(); i++)
            {
                if (save[i].name == name_mat)
                {
                    if (save[i].row != save[i].col)
                    {
                        cout << "matrix morabai nist !!!!" << endl;
                        //mitoni yedone exception ham throw koni!!!
                        break;
                    }
                    inverse(save, i, new_name);
                    break;
                }
                
            }
        }
        else if (get == "show")
        {
            string name_mat;
            getline(cin, name_mat);

            for (size_t i = 0; i < save.size(); i++)
            {
                if (save[i].name == name_mat)
                {
                    show(save, i);
                    break;
                }
                
            }
            
        }
        else if (get == "delete")
        {
            string name_mat;
            getline(cin, name_mat, ' ');

            for (size_t i = 0; i < save.size(); i++)
            {
                if (save[i].name == name_mat)
                {
                    del(save, i);
                    break;
                }
                
            }
        }
        else if (get == "change")
        {
            string name_mat;
            getline(cin, name_mat, ' ');
        
            for (size_t i = 0; i < save.size(); i++)
            {
                if (save[i].name == name_mat)
                {
                    change(save, i);
                    break;
                }
                
            }
            
        }
        else if (get == "help")
        {
            menu();
        }
        
        
        
        cout << "dastor badi ra vared konid....." << endl;
        fflush(stdin);

        getline(cin, get, ' ');//get function 
        transform(get.begin(), get.end(), get.begin(), ::tolower); //lower case string
        if (get == "add")
        {
            string temp;
            getline(cin, temp, ' ');
            get += " " + temp;
            transform(get.begin(), get.end(), get.begin(), ::tolower);
        }
    }

    for (size_t i = 0; i < save.size(); i++)//az dorost bodanesh motman nistam
    {    
        delete [] save[i].arr[i];  
        delete [] save[i].arr;
    }
    
    
    cout << "ba bye:)" << endl;

    return 0;
}