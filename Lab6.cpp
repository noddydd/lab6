#include <iostream>
#include <cmath>

using namespace std;


int regular_simulator(float beta, float gamma, float fraction,
                      bool intervention_array[],
                      int init_inf,
                      int population,
                      int duration)
{
    /**
     * \param beta: infection rate
     * \param gamma: recovery rate
     * \param fraction: government intervention rate, the infection rate after intervention
     *                  should be original infection rate times fraction
     * \param intervention_array: boolean array, records the intervention days in the whole disease duration
     * \param init_inf: initial number of infected persons at beginning
     * \param population: total number of people
     * \param duration: the total time span of the simulation in days
     * \return return the maximum number of the infected persons in the disease duration
     * **/
    int inf = init_inf;
    int susc = population - init_inf;
    int rec = 0;
    int max_inf = init_inf;

    for (int t = 0; t < duration; t++){
        float cur_beta = beta;
        if(intervention_array[t])
            cur_beta = beta * fraction;

        // TODO 1: Implement the regular simulator.

        // Implement TODO 1 here. You need to update inf, susc, rec.
        
        // End of TODO 1.
//        cout << "| " << t << "\t| " << inf << "\t\t\t| " << susc << "\t\t\t| " << rec << "\t\t\t|" << endl;
        if (inf > max_inf)
            max_inf = inf;
    }
    return max_inf;
}


// TODO 2: Implement the recursive simulator from scratch.
// DO NOT use the for loop in this function.
// The return value should be as same as the regular simulator, but the parameters can be different.

// End of TODO 2.


// Initialize the intervention array. The true means that the government intervened on that day.
// Hint: Maybe it is not suitable for more than one intervention.
void initialize_intervention_array(bool intervention[], int start_time, int end_time, int duration){
    for (int t = 0; t < duration; t++){
        if (t >= start_time && t < end_time)
            intervention[t] = true;
        else
            intervention[t] = false;
    }
}


int main()
{
    int mode = 1;
    float beta = 0.5;
    float gamma = 0.3;
    float fraction = 0.5;
    int population = 1000;
    int initial_inf = 20;
    int duration = 60;

    int default_flag = 1;
    cout << "Base parameters of the simulator: " << endl;
    cout << "Infection rate: 0 < beta < 1: " << endl;
    cout << "Recovery rate: 0 < gamma < 1: " << endl;
    cout << "Government intervention fraction: 0 < fraction < 1: " << endl;
    cout << "Total population: population > 0: " << endl;
    cout << "Number of infected persons: initial_inf < population: " << endl;
    cout << "Duration days: duration > 0: " << endl << endl;
    cout << "Input 0 to use default parameters, or input 1 to set new parameters: " << endl;
    cin >> default_flag;
    if (default_flag == 1){
        cout << "Setting new parameters for simulator: " << endl;
        cout << "Input infection rate (beta): " << endl;
        cin >> beta;
        cout << "Input recovery rate (gamma): " << endl;
        cin >> gamma;
        cout << "Input government intervention fraction (fraction): " << endl;
        cin >> fraction;
        cout << "Input total population (population): " << endl;
        cin >> population;
        cout << "Input number of infected persons (initial_inf): " << endl;
        cin >> initial_inf;
        cout << "Input duration days (duration): " << endl;
        cin >> duration;
    }
    else{
        cout << "Default parameters of the simulator: " << endl;
        cout << "Infection rate (beta): " << beta << endl;
        cout << "Recovery rate (gamma): " << gamma << endl;
        cout << "Government intervention fraction (fraction): " << fraction << endl;
        cout << "Total population (population): " << population << endl;
        cout << "Number of infected persons (initial_inf): " << initial_inf << endl;
        cout << "Duration days (duration): " << duration << endl;
    }

    bool intervention_array[duration];
    int init_susc = population - initial_inf;
    int init_rec = 0;
    int max_inf = 0;

    while(mode != 0){
        cout << endl << "Main menu: " << endl;
        cout << "1: Regular simulator " << endl;
        cout << "2: Recursive simulator" << endl;
        cout << "3: Compute government interventions" << endl;
        cout << "0: Exit" << endl;
        cout << "Enter number to choose the task: " << endl;
        cin >> mode;
        while(mode != 0 && mode != 1 && mode != 2 && mode != 3){
            cout << "Input error. " << endl <<
                 "Enter 1 to test the regular simulator, enter 2 to test the recursive simulator, "
                 "enter 3 to compute government interventions, or enter 0 to exit." << endl;
            cin >> mode;
        }

        if (mode == 1 || mode == 2){
            int intervention_start_time, intervention_end_time;
            cout << "Input the start time of the government intervention: " << endl;
            cin >> intervention_start_time;
            cout << "Input the end time of the government intervention: " << endl;
            cin >> intervention_end_time;
            initialize_intervention_array(intervention_array, intervention_start_time, intervention_end_time, duration);

            if (mode == 1) {
                // TODO 1
                max_inf = regular_simulator(beta, gamma, fraction, intervention_array, initial_inf, population, duration);
                // End of TODO 1
                cout << "=================================================================================" << endl;
                cout << "The maximum number of infected persons is " << max_inf << "." << endl;
                cout << "=================================================================================" << endl;
            }
            else{
                // TODO 2
                max_inf = 0; // temporary for code to compile, you need to modify it: max_inf = recursive_simulator(...)
                // End of TODO 2
                cout << "=================================================================================" << endl;
                cout << "The maximum number of infected persons is " << max_inf << "." << endl;
                cout << "=================================================================================" << endl;
            }
        }
        else if(mode == 3){
            // TODO 3: Find the best starting and ending time of the two interventions to obtain the minimum number of total infected persons.
            // 1. The total intervention time of the two interventions should be 20; duration_a + duration_b = 20.
            // 2. duration > 20.
            // 3. Use the regular_simulator or recursive_simulator to find the maximum number of total infected persons.
            int max_intervention_duration = 20;
            int best_start_a = 0;
            int best_end_a = 0;
            int best_start_b = 0;
            int best_end_b = 0;
            int max_infected = 9999999;

            // Implement TODO 3 here.

            cout << "=================================================================================" << endl;
            cout << "best_start_a: " << best_start_a << endl;
            cout << "best_end_a: " << best_end_a << endl;
            cout << "best_start_b: " << best_start_b << endl;
            cout << "best_end_b: " << best_end_b << endl;
            cout << "max_infected: " << max_infected << endl;
            cout << "If the first government intervention ranges from " << best_start_a << " to " << best_end_a
                 << ", second intervention ranges from " << best_start_b << " to " << best_end_b
                 << ", we can reduce the maximum of total infected persons to " << max_infected << "." << endl;
            cout << "=================================================================================" << endl;
            // End of TODO 3
        }
        else{
            cout << "Exit." << endl;
        }
    }
    return 0;
}