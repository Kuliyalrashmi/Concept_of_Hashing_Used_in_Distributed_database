#include<bits/stdc++.h>

using namespace std;


class ConsistentHashing{
    private:
    map<int , string> hash_ring; 
    map<string, int > data_mapping; 
    int  hash_space;
    public:

    ConsistentHashing(int space_size) {
        hash_space = space_size;
        cout << "Consistent Hashing initialized with hash space of size: " << space_size << endl;
    }

    int find_closest_node(int key_hash) {
        auto it = hash_ring.upper_bound(key_hash);
        if (it == hash_ring.end()) {
            return hash_ring.begin()->first;
        }
        return it->first;
    }

    int hash_function(string key) {
        int sum = 0;
        for (unsigned char c : key) {
            sum += c;
        }
        return sum % hash_space; 
    }

    void add_node(const string& node_name) {
        int node_hash = hash_function(node_name);
        hash_ring[node_hash] = node_name;
        cout << "Node " << node_name << " added at position " << node_hash << " on the ring.\n";
    }


    void remove_node(const string& node_name) {
        int node_hash = hash_function(node_name);
        if (hash_ring.erase(node_hash)) {
            cout << "Node " << node_name << " removed from the ring.\n";
        } else {
            cout << "Node " << node_name << " not found on the ring.\n";
        }
    }

    void put_data(const string& key, const string& value) {
        int key_hash = hash_function(key);
        int node_hash = find_closest_node(key_hash);
        data_mapping[key] = node_hash;
        cout << "Key '" << key << "' (hash " << key_hash << ") is mapped to node at " << node_hash << " (" << hash_ring[node_hash] << ").\n";
    }

    string fetch_data(const string& key) {
        if (data_mapping.find(key) == data_mapping.end()) {
            cout << "Key '" << key << "' not found.\n";
            return "";
        }
        int node_hash = data_mapping[key];
        cout << "Key '" << key << "' is associated with node at " << node_hash << " (" << hash_ring[node_hash] << ").\n";
        return hash_ring[node_hash];
    }

};


int main() {
    int option, hash_space_size;
    string key, value, node_name;

    cout << "Define Hash Space Size for the System: ";
    cin >> hash_space_size;

    ConsistentHashing con_hash(hash_space_size);

    cout << "-------------- CONSISTENT HASHING SIMULATION -------------" << endl;
    cout << "Options:\n1. Add Node\n2. Remove Node\n3. Insert Data\n4. Fetch Data\n5. Exit\n";

    while (true) {
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter Node Name to Add: ";
                cin >> node_name;
                con_hash.add_node(node_name);
                break;

            case 2:
                cout << "Enter Node Name to Remove: ";
                cin >> node_name;
                con_hash.remove_node(node_name);
                break;

            case 3:
                cout << "Enter Key and Value: ";
                cin >> key >> value;
                con_hash.put_data(key, value);
                break;

            case 4:
                cout << "Enter Key to Fetch Value: ";
                cin >> key;
                con_hash.fetch_data(key);
                break;

            case 5:
                cout << "Exiting the simulation. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}
