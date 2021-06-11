const nemo = ['nemo'];
const everyone = ["dory", "bruce", "marlin", "nemo", "gill", "bloat", "nigel", "squirt", "darla", "hank"];
const large = new Array(100).fill('nothing', 'nemo');
const huge = new Array(100000).fill('nothing', 'nemo');

const findNemo = (array) => {
  let count = 0;
  for(let i = 0; i < array.length; i++) {
    if (array[i] === 'nemo') {
      count++;
    }
  }
  console.log("Nemo was found " + count + " times.");
};

findNemo(everyone);
findNemo(large);
findNemo(huge);