class HashTable {
    constructor(size){
        this.data = new Array(size);
    }

    _hash(key) {
        let hash = 0;
        for (let i=0; i < key.length; i++) {
            hash = (hash + key.charCodeAt(i) * i) % this.data.length;
        }
        return hash;
    }

    get(key) {
        const keyHash = this._hash(key);
        return this.data[keyHash];
    }

    set(key, value) {
        const address = this._hash(key);
        if(!this.data[address]) {
            this.data[address] = [];
        }

        this.data[address].push([key, value]);
    }
}





// // =========== Runner ================
// const myHashTable = new HashTable(50);
// myHashTable.set('grapes', 10000);
// myHashTable.set('apples', 5);
// myHashTable.set('Sam', {age: 40, hair_color: "blond", height: 4.2});
// console.log(myHashTable.get('grapes'));
// console.log(myHashTable.get("apples"));
// console.log(myHashTable.get("Sam"));



// Bounus: Figure out how to get 2 to match instead of 5 below.
function Duplicates(input) {
    let found = {};
    for(item in input) {
        if(input[item] in found) {
            return input[item];
        }
        found[input[item]] = 1;
    }
    return undefined;
}

console.log(Duplicates([2,5,1,5,2,3,5,1,2,4]));
