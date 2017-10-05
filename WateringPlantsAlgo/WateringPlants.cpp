#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	const int UNITS_PER_CAN = 3;
	const string INPUT_FILE_NAME = "counts.txt";
	int plant_count;
	ifstream input;
	input.open(INPUT_FILE_NAME.c_str(), ios_base::in);
	if (input.fail()) {
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
		return -1;
	}

	// Loop once for each number of plants read from the input file.
	// Stop when the number of plants is 0 or less.
	// During each loop, simulate Plan Near and Plan Far.
	do {
		input >> plant_count;
		if (plant_count == 0) {
			continue;
		}
		// Plan Near
		cout << endl;
		cout << "==========================" << endl;
		cout << " Plan Near with " << plant_count << " plants" << endl;
		cout << "==========================" << endl;
		cout << endl;
		cout << "Where          Cum. steps     Water amt.     Cum. step-units"
				<< endl;
		cout << "---------      ----------     ----------     ---------------"
				<< endl;
		/*** Complete the code for Plan Near. ***/
		int stepUnits = 0;
		int plantsCovered = 0;
		int totalStepsTaken = 0;
		for (int i = 1; i < plant_count; i++) {
			if (plantsCovered >= plant_count) {
				break;
			}
			int steps = plantsCovered + 1;
			for (int waterQuant = UNITS_PER_CAN; waterQuant != -1;
					waterQuant--) {

				if (plantsCovered == plant_count) {

					stepUnits += (plantsCovered * waterQuant);
					totalStepsTaken += plantsCovered;
					cout << "FAUCET   " << "          " << setw(3)
							<< totalStepsTaken << "          " << setw(3)
							<< waterQuant << "          " << setw(3)
							<< stepUnits << endl;
					break;
				} else {
					stepUnits += waterQuant * steps;
					if (waterQuant == 0) {
						totalStepsTaken += plantsCovered;
						cout << "FAUCET   " << "          " << setw(3)
								<< totalStepsTaken << "          " << setw(3)
								<< waterQuant << "          " << setw(3)
								<< stepUnits << endl;
					} else {
						totalStepsTaken += steps;
						plantsCovered++;
						cout << "Plant" << " " << setw(3) << plantsCovered
								<< "          " << setw(3) << totalStepsTaken
								<< "          " << setw(3) << waterQuant
								<< "          " << setw(3) << stepUnits << endl;
					}
					steps = 1;
				}
			}
		}

		cout << endl << "Plan Near: " << "Total Steps = " << totalStepsTaken
				<< ", " << "total step-units = " << stepUnits;

		// Plan Far
		cout << endl << endl;
		cout << "=========================" << endl;
		cout << " Plan Far with " << plant_count << " plants" << endl;
		cout << "=========================" << endl;
		cout << endl;
		cout << "Where        Cum. steps    Water amt.    Cum. step-units"
				<< endl;
		cout << "---------    ----------    ----------    ---------------"
				<< endl;

		/*** Complete the code for Plan Far. ***/
		int stepUnitsFar = 0;
		int plantsCoveredFar = 0;
		int totalStepsTakenFar = 0;
		for (int i = 1; i < plant_count; i++) {
			if (plantsCoveredFar >= plant_count) {
				break;
			}
			int steps = (plant_count - plantsCoveredFar);
			for (int waterQuant = UNITS_PER_CAN; waterQuant != -1;
					waterQuant--) {

				if (plantsCoveredFar == plant_count) {
					stepUnitsFar += (waterQuant);
					totalStepsTakenFar += 1;
					cout << "FAUCET  " << "          " << setw(3)
							<< totalStepsTakenFar << "          " << setw(3)
							<< waterQuant << "          " << setw(3)
							<< stepUnitsFar << endl;
					break;
				} else {
					stepUnitsFar += (waterQuant * steps);
					if (waterQuant == 0) {
						totalStepsTakenFar += (plant_count
								- (plantsCoveredFar - 1));
						cout << "FAUCET  " << "          " << setw(3)
								<< totalStepsTakenFar << "          " << setw(3)
								<< waterQuant << "          " << setw(3)
								<< stepUnitsFar << endl;
					} else {
						totalStepsTakenFar += steps;
						plantsCoveredFar++;
						cout << "Plant" << "" << setw(3)
								<< (plant_count - (plantsCoveredFar - 1))
								<< "          " << setw(3) << totalStepsTakenFar
								<< "          " << setw(3) << waterQuant
								<< "          " << setw(3) << stepUnitsFar
								<< endl;
					}
					steps = 1;
				}
			}
		}
		// Which plan is better? Better means fewer step-units.
		cout << endl << "Plan Far: " << "Total Steps = " << totalStepsTakenFar
				<< ", " << "total step-units = " << stepUnitsFar;
		cout << endl << endl;
		cout << "*** With " << plant_count << " plants, ";

		/*** Complete the code to determine the better plan. ***/
		if (stepUnitsFar < stepUnits) {
			cout << "Plan Far is better with " << (stepUnits - stepUnitsFar)
					<< " fewer step-units." << endl;
		} else {
			cout << "Plan Near is better with " << (stepUnitsFar - stepUnits)
					<< " fewer step-units." << endl;
		}

	} while (plant_count > 0);

	return 0;
}
