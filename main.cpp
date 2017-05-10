    #include <iostream>
    #include <fstream>
    #include <string>
    #include <random>
    #include <ctime>
    #include <cctype>
    #include <cstdlib>

    using namespace std;

    int NeuralNetworkAction(double sinapses[15], int s_neurons[15], int letter[15], const double step);
    void ReadFunc(int letter_bits[15]);

    int main(int argc, char *argv[])
    {
        //Letter's bits

        int letters[10][15] = {
            {1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
            {0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1},
            {1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
            {1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
            {1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
            {1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
            {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1}
        };

        int wrong51 [15] = {1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1};
        int wrong52 [15] = {0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1};
        int wrong53 [15] = {1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};


        /*
         *  Neural network creation
        */

        //Sensors
        int S_neurons [15];

        //R-neurons
        int R_neuron_out;

        //Activation function
        const double bias = 0.9;

        //Sinapses
        double weights [15] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

        /*
         * Training
        */

        int train_num;

        for(int i = 0; i < 10000; i++){
            //Choosing train_num
            train_num = rand() % 10;

            //Network is in action
            R_neuron_out = NeuralNetworkAction(weights, S_neurons, letters[train_num], bias);

            //Correcting weights
            if(train_num == 5 && R_neuron_out == 0){
                for(int k = 0; k < 15; k++){
                    if(S_neurons[k] == 1)   weights[k]+=0.1;
                }
                //increasing weights
            }else if(train_num != 5 && R_neuron_out == 1){
                for(int k = 0; k < 15; k++){
                    if(S_neurons[k] == 1)   weights[k]-=0.1;
                }
                //decreasing weights
            }
            //if train_num is 5 and answer is 5, then everything is ok
        }

        //Training is over. Network is ready

        //Printing weights
        for(int i = 0; i < 15; i++)
            cout << i << " - > " << weights[i] << "\n";


        /*

        //Real action

        R_neuron_out = NeuralNetworkAction(weights, S_neurons, wrong51, bias);

        if(R_neuron_out == 1)   cout << "Network has recognized 5!\n";
        else                    cout << "Network has't recognized 5...\n";

        R_neuron_out = NeuralNetworkAction(weights, S_neurons, wrong52, bias);

        if(R_neuron_out == 1)   cout << "Network has recognized 5!\n";
        else                    cout << "Network has't recognized 5...\n";

        R_neuron_out = NeuralNetworkAction(weights, S_neurons, wrong53, bias);

        if(R_neuron_out == 1)   cout << "Network has recognized 5!\n";
        else                    cout << "Network has't recognized 5...\n";

        //Num from file

        */

        R_neuron_out = NeuralNetworkAction(weights, S_neurons, letters[0], bias);

        if(R_neuron_out == 1)   cout << "Network has recognized 5!\n";
        else                    cout << "Network has't recognized 5...\n";

        R_neuron_out = NeuralNetworkAction(weights, S_neurons, letters[1], bias);

        if(R_neuron_out == 1)   cout << "Network has recognized 5!\n";
        else                    cout << "Network has't recognized 5...\n";

        R_neuron_out = NeuralNetworkAction(weights, S_neurons, letters[2], bias);

        if(R_neuron_out == 1)   cout << "Network has recognized 5!\n";
        else                    cout << "Network has't recognized 5...\n";

        R_neuron_out = NeuralNetworkAction(weights, S_neurons, letters[3], bias);

        if(R_neuron_out == 1)   cout << "Network has recognized 5!\n";
        else                    cout << "Network has't recognized 5...\n";

        R_neuron_out = NeuralNetworkAction(weights, S_neurons, letters[4], bias);

        if(R_neuron_out == 1)   cout << "Network has recognized 5!\n";
        else                    cout << "Network has't recognized 5...\n";

        R_neuron_out = NeuralNetworkAction(weights, S_neurons, letters[6], bias);

        if(R_neuron_out == 1)   cout << "Network has recognized 5!\n";
        else                    cout << "Network has't recognized 5...\n";

        R_neuron_out = NeuralNetworkAction(weights, S_neurons, letters[7], bias);

        if(R_neuron_out == 1)   cout << "Network has recognized 5!\n";
        else                    cout << "Network has't recognized 5...\n";

        R_neuron_out = NeuralNetworkAction(weights, S_neurons, letters[8], bias);

        if(R_neuron_out == 1)   cout << "Network has recognized 5!\n";
        else                    cout << "Network has't recognized 5...\n";

        R_neuron_out = NeuralNetworkAction(weights, S_neurons, letters[9], bias);

        if(R_neuron_out == 1)   cout << "Network has recognized 5!\n";
        else                    cout << "Network has't recognized 5...\n";

        R_neuron_out = NeuralNetworkAction(weights, S_neurons, letters[5], bias);

        if(R_neuron_out == 1)   cout << "Network has recognized 5!\n";
        else                    cout << "Network has't recognized 5...\n";


        cout << "\nAnd now the most interesting!\n";

        int our_five[15];
        ReadFunc(our_five);

        R_neuron_out = NeuralNetworkAction(weights, S_neurons, our_five, bias);

        if(R_neuron_out == 1)   cout << "Network has recognized 5!\n";
        else                    cout << "Network has't recognized 5...\n";

        cout << endl;

    }

    int NeuralNetworkAction(double sinapses[15], int s_neurons[15], int letter[15], const double step)
    {
        int R_neuron_summator;

        //Giving num to our Network
        for(int k = 0; k < 15; k++)
            s_neurons[k] = letter[k];

        //Finding summary and giving it to the R_neuron
        for(int k = 0; k < 15; k++)
            R_neuron_summator += s_neurons[k]*sinapses[k];

        //Choosing if the train_num is '5'
        if(R_neuron_summator > step)   return 1;
        return 0;
    }


    void ReadFunc(int letter_bits[15]){

        ifstream fstr("1");
        //int letter_bits[15];
        //Reading

        string str;
        string tmp;
        char c [1];

        while (!fstr.eof()){
            str.append(tmp);
            fstr >> tmp;
        }

        //cout << str << endl;

        for(int i = 0; i < 15; i++){
            c[0] = str[i];
            letter_bits[i] = atoi(c);
        }

        /*
        for(int i = 0; i < 15; i++)
            cout << letter_bits[i] << endl;
        */

        //return letter_bits;
    }


    /*
     *
     * Saving working core
     *
     *
    //Giving train_num to our Network
    for(int k = 0; k < 15; k++)
        S_neurons[k] = letters[train_num][k];

    //Finding summary and giving it to the R_neuron
    for(int k = 0; k < 15; k++)
        R_neuron_summator += S_neurons[k]*weights[k];

    //Choosing if the train_num is '5'
    if(R_neuron_summator > bias)   R_neuron_out = 1;
    else                           R_neuron_out = 0;

    //Network has made it's choise========================
    //*/
