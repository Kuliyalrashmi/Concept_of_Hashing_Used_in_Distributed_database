#include<bits/stdc++.h>
using namespace std;

class ConsistentHashing{
    private:
    unordered_map<int,string>storage_nodes;
    unordered_map<string, int> data_mapping;
    int storage_size;

    public:
    
    ConsistentHashing(int size){
        cout<<"Started Hashing with storage nodes : "<<size<<endl;
        storage_size = size;
    }

    int hash_function(string key){
        int sum= 0;

        for(unsigned char c : key){
            sum += c;
        }

        return sum % storage_size; 
    }

    int put_data(const string& key, const string& value){
        int storage_index = hash_function(key);

        if(storage_nodes.count(storage_index)){
            cout << "Collision detected. Overwriting value at storage node: " << storage_index << endl;
        }

        storage_nodes[storage_index] = value;
        data_mapping[key] = storage_index;
        cout<<"Value stored in "<<storage_index<<endl;

        return storage_index;
    }

    string fetch_data(string key){
        int storage_index = hash_function(key);
        if(storage_nodes.count(storage_index))
            return storage_nodes[storage_index];

        cout<< "No Value associated to the key : "<<storage_index<<endl;
        return "";
    }

    int scale_up(int new_size) {
        int migrated_data = 0;
        unordered_map<string, int> new_data_mapping;

        cout << "\nScaling up to " << new_size << " nodes.\n";
        for (const auto& pair : data_mapping) {
            const string& key = pair.first;
            int old_index = pair.second;

            int new_index = hash_function(key) % new_size;
            new_data_mapping[key] = new_index;
            if (new_index != old_index) {
                migrated_data++;
            }
        }

        storage_size = new_size;
        data_mapping = new_data_mapping; 
        cout << migrated_data << " keys migrated during scale-up.\n";

        return migrated_data;
    }

    int scale_down(int new_size) {
        int migrated_data = 0;
        unordered_map<string, int> new_data_mapping;

        cout << "\nScaling down to " << new_size << " nodes.\n";
        for (const auto& pair : data_mapping) {
            const string& key = pair.first;
            int old_index = pair.second;

            int new_index = hash_function(key) % new_size;
            new_data_mapping[key] = new_index;
            if (new_index != old_index) {
                migrated_data++;
            }
        }

        storage_size = new_size;
        data_mapping = new_data_mapping;
        cout << migrated_data << " keys migrated during scale-down.\n";

        return migrated_data;
    }

};


int main(){

    int nodes , option , new_size;
    string key , value;

    cout << "Define Total Storage Nodes for System : ";
    cin >> nodes;


    ConsistentHashing con_hash(nodes);

    cout << "-------------- WELCOME TO A DEMO SIMULATION OF HASHING -------------" << endl;
    cout << "Options:\n1. Insert Data\n2. Fetch Data\n3. Scale Up\n4. Scale Down\n5. Exit\n";

    while(true){

        cin>>option;

        switch (option)
        {
            case 1:
                cout<<"Enter Key with their Respective Value : "<<endl; 
                cin >>key >> value;

                con_hash.put_data(key , value);
                break;

            case 2:
                cout << "Enter Key to Fetch Value: ";
                cin >> key;
                cout << "Value: " << con_hash.fetch_data(key) << endl;
                break;
            case 3:
            cout << "Enter New Number of Nodes: ";
            cin >> new_size;
            con_hash.scale_up(new_size);
            break;

        case 4:
            cout << "Enter New Number of Nodes: ";
            cin >> new_size;
            con_hash.scale_down(new_size);
            break;

        case 5:
            cout << "Exiting the simulation. Goodbye!" << endl;
            return 0;

        default:
            cout << "Invalid option. Please try again." << endl;
    }

    return 0;
}
