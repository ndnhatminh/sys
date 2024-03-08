#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
int firstMeet(int& exp1, int& exp2, int e1)
{
	if ((e1 < 0) || (e1 > 99))
	{
		return -99;
	}
	if (exp1 < 0)
	{
		exp1 = 0;
	}

	if (exp1 > 600)
	{
		exp1 = 600;
	}
	if (exp2 < 0)
	{
		exp2 = 0;
	}
	if (exp2 > 600)
	{
		exp2 = 600;
	}
	if (e1 == 0)
	{

		exp2 = exp2 + 29;
		if (exp2 < 0)
		{
			exp2 = 0;
		}
		if (exp2 > 600)
		{
			exp2 = 600;
		}
		int D = e1 * 3 + exp1 * 7;
		if (D % 2 == 0)
		{
			exp1 = ceil(exp1 + D / 200.0);
			if (exp1 < 0)
			{
				exp1 = 0;
			}

			if (exp1 > 600)
			{
				exp1 = 600;
			}
		}
		else {
			exp1 = ceil(exp1 - D / 100.0);
			if (exp1 < 0)
			{
				exp1 = 0;
			}

			if (exp1 > 600)
			{
				exp1 = 600;
			}
		}
	}
	if (e1 == 1)
	{
		exp2 = exp2 + 45;
		if (exp2 < 0)
		{
			exp2 = 0;
		}
		if (exp2 > 600)
		{
			exp2 = 600;
		}
		int D = e1 * 3 + exp1 * 7;
		if (D % 2 == 0)
		{
			exp1 = ceil(exp1 + D / 200.0);
			if (exp1 < 0)
			{
				exp1 = 0;
			}

			if (exp1 > 600)
			{
				exp1 = 600;
			}
		}
		else {
			exp1 = ceil(exp1 - D / 100.0);
			if (exp1 < 0)
			{
				exp1 = 0;
			}

			if (exp1 > 600)
			{
				exp1 = 600;
			}
		}
	}
	if (e1 == 2)
	{
		exp2 = exp2 + 75;
		if (exp2 < 0)
		{
			exp2 = 0;
		}
		if (exp2 > 600)
		{
			exp2 = 600;
		}
		int D = e1 * 3 + exp1 * 7;
		if (D % 2 == 0)
		{
			exp1 = ceil(exp1 + D / 200.0);
			if (exp1 < 0)
			{
				exp1 = 0;
			}

			if (exp1 > 600)
			{
				exp1 = 600;
			}
		}
		else {
			exp1 = ceil(exp1 - D / 100.0);
			if (exp1 < 0)
			{
				exp1 = 0;
			}

			if (exp1 > 600)
			{
				exp1 = 600;
			}
		}
	}
	if (e1 == 3)
	{
		exp2 = exp2 + 149;
		if (exp2 < 0)
		{
			exp2 = 0;
		}
		if (exp2 > 600)
		{
			exp2 = 600;
		}
		int D = e1 * 3 + exp1 * 7;
		if (D % 2 == 0)
		{
			exp1 = ceil(exp1 + D / 200.0);
			if (exp1 < 0)
			{
				exp1 = 0;
			}

			if (exp1 > 600)
			{
				exp1 = 600;
			}
		}
		else {
			exp1 = ceil(exp1 - D / 100.0);
			if (exp1 < 0)
			{
				exp1 = 0;
			}

			if (exp1 > 600)
			{
				exp1 = 600;
			}
		}
	}


	if ((e1 >= 4) && (e1 <= 19))
	{
		exp2 = ceil(exp2 + (e1 / 4.0 + 19));
		if (exp2 < 0)
		{
			exp2 = 0;
		}
		if (exp2 > 600)
		{
			exp2 = 600;
		}
		exp1 = exp1 - e1;
		if (exp1 < 0)
		{
			exp1 = 0;
		}

		if (exp1 > 600)
		{
			exp1 = 600;
		}
	}
	if ((e1 >= 20) && (e1 <= 49))
	{
		exp2 = ceil(exp2 + (e1 / 9.0 + 21));
		if (exp2 < 0)
		{
			exp2 = 0;
		}
		if (exp2 > 600)
		{
			exp2 = 600;
		}
		exp1 = exp1 - e1;
		if (exp1 < 0)
		{
			exp1 = 0;
		}

		if (exp1 > 600)
		{
			exp1 = 600;
		}
	}
	if ((e1 >= 50) && (e1 <= 65))
	{
		exp2 = ceil(exp2 + (e1 / 16.0 + 17));
		if (exp2 < 0)
		{
			exp2 = 0;
		}
		if (exp2 > 600)
		{
			exp2 = 600;
		}
		exp1 = exp1 - e1;
		if (exp1 < 0)
		{
			exp1 = 0;
		}

		if (exp1 > 600)
		{
			exp1 = 600;
		}
	}
	if ((e1 >= 66) && (e1 <= 79))
	{
		exp2 = ceil(exp2 + (e1 / 4.0 + 19));
		if (exp2 < 0)
		{
			exp2 = 0;
		}
		if (exp2 > 600)
		{
			exp2 = 600;
		}
		if (exp2 > 200)
		{
			exp2 = ceil(exp2 + (e1 / 9.0 + 21));
			if (exp2 < 0)
			{
				exp2 = 0;
			}
			if (exp2 > 600)
			{
				exp2 = 600;
			}
		}
		exp1 = exp1 - e1;
		if (exp1 < 0)
		{
			exp1 = 0;
		}

		if (exp1 > 600)
		{
			exp1 = 600;
		}
	}
	if ((e1 >= 80) && (e1 <= 99))
	{
		exp2 = ceil(exp2 + (e1 / 4.0 + 19));
		if (exp2 < 0)
		{
			exp2 = 0;
		}
		if (exp2 > 600)
		{
			exp2 = 600;
		}
		exp2 = ceil(exp2 + (e1 / 9.0 + 21));
		if (exp2 < 0)
		{
			exp2 = 0;
		}
		if (exp2 > 600)
		{
			exp2 = 600;
		}
		if (exp2 > 400)
		{
			exp2 = ceil(exp2 + (e1 / 16.0 + 17));
			if (exp2 < 0)
			{
				exp2 = 0;
			}
			if (exp2 > 600)
			{
				exp2 = 600;
			}
			exp2 = ceil(exp2 + 0.15 * exp2);
			if (exp2 < 0)
			{
				exp2 = 0;
			}
			if (exp2 > 600)
			{
				exp2 = 600;
			}

		}


		exp1 = exp1 - e1;
		if (exp1 < 0)
		{
			exp1 = 0;
		}

		if (exp1 > 600)
		{
			exp1 = 600;
		}
	}


	if (exp1 < 0)
	{
		exp1 = 0;
	}
	if (exp2 < 0)
	{
		exp2 = 0;
	}
	if (exp1 > 600)
	{
		exp1 = 600;
	}
	if (exp2 > 600)
	{
		exp2 = 600;
	}
	return  exp1 + exp2;

}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{

	if ((E2 > 99) || (E2 < 0))
	{
		return -99;
	}
	else {
		if (HP1 > 666)
		{
			HP1 = 666;
		}
		if (HP1 < 0)
		{
			HP1 = 0;
		}
		if (EXP1 > 600)
		{
			EXP1 = 600;
		}
		if (EXP1 < 0)
		{
			EXP1 = 0;
		}
		if (M1 > 3000)
		{
			M1 = 3000;
		}
		if (M1 < 0)
		{
			M1 = 0;
		}
		int S = pow(round(sqrt(EXP1)), 2);
		float M = 0.5 * M1;
		float P;
		float p3 = 0.00;
		float p1 = 0.00, p2 = 0.00;
		if (M1 == 0)
		{
			if (EXP1 >= S)
			{
				p1 = 1;
			}
			else {
				p1 = ((EXP1 * 1.00) / (S * 1.00) + 80) / 123.00;
			}
			EXP1 = ceil(EXP1 + EXP1 * 0.17);
			if (EXP1 > 600)
			{
				EXP1 = 600;
			}
			if (EXP1 < 0)
			{
				EXP1 = 0;
			}
			HP1 = ceil(HP1 - HP1 * 0.17);
			if (HP1 > 666)
			{
				HP1 = 666;
			}
			if (HP1 < 0)
			{
				HP1 = 0;
			}

			if (EXP1 >= S)
			{
				p2 = 1;
			}
			else
			{
				p2 = ((EXP1 * 1.00) / (S * 1.00) + 80) / 123.00;
			}


			float a[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };

			if (E2 < 10)
			{
				p3 = a[E2];
			}
			else
			{
				E2 = E2 % 10 + E2 / 10;
				E2 = E2 % 10;


			}
			p3 = a[E2] / 100.0;
			if ((p1 == p2) && (p1 == p3) && (p2 == p3))
			{
				EXP1 = ceil(EXP1 - 0.25 * EXP1);
				if (EXP1 > 600)
				{
					EXP1 = 600;
				}
				if (EXP1 < 0)
				{
					EXP1 = 0;
				}
			}
			else
			{
				P = ((p1 + p2 + p3) / 3 * 1.00);
				if (P >= 0.5)
				{
					HP1 = ceil(HP1 - 0.1 * HP1);
					if (HP1 > 666)
					{
						HP1 = 666;
					}
					if (HP1 < 0)
					{
						HP1 = 0;
					}
					EXP1 = ceil(EXP1 + 0.2 * EXP1);
					if (EXP1 > 600)
					{
						EXP1 = 600;
					}
					if (EXP1 < 0)
					{
						EXP1 = 0;
					}
				}
				else {
					HP1 = ceil(HP1 - 0.15 * HP1);
					if (HP1 > 666)
					{
						HP1 = 666;
					}
					if (HP1 < 0)
					{
						HP1 = 0;
					}
					EXP1 = ceil(EXP1 + 0.15 * EXP1);
					if (EXP1 > 600)
					{
						EXP1 = 600;
					}
					if (EXP1 < 0)
					{
						EXP1 = 0;
					}
				}

				return HP1 + EXP1 + M1;

			}
		}
		else if (M1 > 0)
		{


			if (EXP1 >= S)
			{
				p1 = 1;
			}
			else {
				p1 = ((EXP1 * 1.00) / (S * 1.00) + 80) / 123.00;
			}
			int phi = 0, phi1, phi2, phi3;
			if (E2 % 2 != 0)
			{
				while (phi < M)
				{
					if (phi > M) {
						break;
					}
					if (HP1 < 200)
					{
						HP1 = ceil(HP1 + HP1 * 0.3);
						if (HP1 > 666)
						{
							HP1 = 666;
						}
						if (HP1 < 0)
						{
							HP1 = 0;
						}
						M1 = M1 - 150;
						phi1 = 150;
						phi = phi + phi1;

						if (phi > M) {
							break;
						}
						if (EXP1 < 400)
						{
							EXP1 = ceil(EXP1 + EXP1 * 0.13);
							if (EXP1 > 600)
							{
								EXP1 = 600;
							}
							if (EXP1 < 0)
							{
								EXP1 = 0;
							}
							M1 = M1 - 200;
							phi2 = 200;
							phi = phi + phi2;
							if (phi > M) {
								break;
							}
							if (EXP1 < 300)
							{
								M1 = M1 - 100;
								EXP1 = ceil(EXP1 - EXP1 * 0.1);
								if (EXP1 > 600)
								{
									EXP1 = 600;
								}
								if (EXP1 < 0)
								{
									EXP1 = 0;
								}

								phi3 = 100;
								phi = phi + phi3;
								if (phi > M) {
									break;
								}

							}
							else {

								M1 = M1 - 120;
								EXP1 = ceil(EXP1 - EXP1 * 0.1);
								if (EXP1 > 600)
								{
									EXP1 = 600;
								}
								if (EXP1 < 0)
								{
									EXP1 = 0;
								}
								phi3 = 120;
								phi = phi + phi3;
								if (phi > M) {
									break;
								}
							}
						}
						else {

							EXP1 = ceil(EXP1 + EXP1 * 0.13);
							if (EXP1 > 600)
							{
								EXP1 = 600;
							}
							if (EXP1 < 0)
							{
								EXP1 = 0;
							}
							M1 = M1 - 120;
							phi2 = 120;
							phi = phi + phi2;
							if (phi > M) {
								break;
							}
							if (EXP1 < 300)
							{
								M1 = M1 - 100;
								EXP1 = ceil(EXP1 - EXP1 * 0.1);
								if (EXP1 > 600)
								{
									EXP1 = 600;
								}
								if (EXP1 < 0)
								{
									EXP1 = 0;
								}
								phi3 = 100;
								phi = phi + phi3;
								if (phi > M) {
									break;
								}
							}
							else {
								M1 = M1 - 120;
								EXP1 = ceil(EXP1 - EXP1 * 0.1);
								if (EXP1 > 600)
								{
									EXP1 = 600;
								}
								if (EXP1 < 0)
								{
									EXP1 = 0;
								}
								phi3 = 120;
								phi = phi + phi3;
								if (phi > M) {
									break;
								}
							}
						}
					}
					else
					{

						HP1 = ceil(HP1 + 0.1 * HP1);
						if (HP1 > 666)
						{
							HP1 = 666;
						}
						if (HP1 < 0)
						{
							HP1 = 0;
						}
						M1 = M1 - 70;
						phi1 = 70;
						phi = phi + phi1;
						if (phi > M) {
							break;
						}
						if (EXP1 < 400)
						{
							EXP1 = ceil(EXP1 + EXP1 * 0.13);
							if (EXP1 > 600)
							{
								EXP1 = 600;
							}
							if (EXP1 < 0)
							{
								EXP1 = 0;
							}
							M1 = M1 - 200;
							phi2 = 200;
							phi = phi + phi2;
							if (phi > M) {
								break;
							}
							if (EXP1 < 300)
							{
								M1 = M1 - 100;
								EXP1 = ceil(EXP1 - EXP1 * 0.1);
								if (EXP1 > 600)
								{
									EXP1 = 600;
								}
								if (EXP1 < 0)
								{
									EXP1 = 0;
								}
								phi3 = 100;
								phi = phi + phi3;
								if (phi > M) {
									break;
								}
							}
							else {
								M1 = M1 - 120;
								EXP1 = ceil(EXP1 - EXP1 * 0.1);
								if (EXP1 > 600)
								{
									EXP1 = 600;
								}
								if (EXP1 < 0)
								{
									EXP1 = 0;
								}
								phi3 = 120;
								phi = phi + phi3;
								if (phi > M) {
									break;
								}
							}
						}
						else {
							EXP1 = ceil(EXP1 + EXP1 * 0.13);
							if (EXP1 > 600)
							{
								EXP1 = 600;
							}
							else if (EXP1 < 0)
							{
								EXP1 = 0;
							}
							M1 = M1 - 120;
							phi2 = 120;
							phi = phi + phi2;
							if (phi > M) {
								break;
							}
							if (EXP1 < 300)
							{
								M1 = M1 - 100;
								EXP1 = ceil(EXP1 - EXP1 * 0.1);
								if (EXP1 > 600)
								{
									EXP1 = 600;
								}
								if (EXP1 < 0)
								{
									EXP1 = 0;
								}
								phi3 = 100;
								phi = phi + phi3;
								if (phi > M) {
									break;
								}
							}
							else {
								M1 = M1 - 120;
								EXP1 = ceil(EXP1 - EXP1 * 0.1);
								if (EXP1 > 600)
								{
									EXP1 = 600;
								}
								if (EXP1 < 0)
								{
									EXP1 = 0;
								}
								phi3 = 120;
								phi = phi + phi3;
								if (phi > M) {
									break;
								}
							}
						}

					}
				}

				HP1 = ceil(HP1 - 0.17 * HP1);
				if (HP1 > 666)
				{
					HP1 = 666;
				}
				if (HP1 < 0)
				{
					HP1 = 0;
				}
				EXP1 = ceil(EXP1 + 0.17 * EXP1);
				if (EXP1 > 600)
				{
					EXP1 = 600;
				}
				if (EXP1 < 0)
				{
					EXP1 = 0;
				}
			}
			else
			{
				if (HP1 < 200)
				{
					HP1 = ceil(HP1 + 0.3 * HP1);
					if (HP1 > 666)
					{
						HP1 = 666;
					}
					if (HP1 < 0)
					{
						HP1 = 0;
					}
					M1 = M1 - 150;
				}
				else {
					HP1 = ceil(HP1 + 0.1 * HP1);
					if (HP1 > 666)
					{
						HP1 = 666;
					}
					if (HP1 < 0)
					{
						HP1 = 0;
					}
					M1 = M1 - 70;
				}
				if (M1 > 0)
				{
					if (EXP1 < 400)
					{
						M1 = M1 - 200;
						EXP1 = ceil(EXP1 + 0.13 * EXP1);
						if (EXP1 > 600)
						{
							EXP1 = 600;
						}
						if (EXP1 < 0)
						{
							EXP1 = 0;
						}
					}
					else
					{
						M1 = M1 - 120;
						EXP1 = ceil(EXP1 + 0.13 * EXP1);
						if (EXP1 > 600)
						{
							EXP1 = 600;
						}
						if (EXP1 < 0)
						{
							EXP1 = 0;
						}
					}
				}
				else
				{
					M1 = 0;
					EXP1 = ceil(EXP1 + EXP1 * 0.17);
					if (EXP1 > 600)
					{
						EXP1 = 600;
					}
					if (EXP1 < 0)
					{
						EXP1 = 0;
					}
					HP1 = ceil(HP1 - HP1 * 0.17);
					if (HP1 > 666)
					{
						HP1 = 666;
					}
					if (HP1 < 0)
					{
						HP1 = 0;
					}
					if (EXP1 >= S)
					{
						p2 = 1;
					}
					else
					{
						p2 = ((EXP1 * 1.00) / (S * 1.00) + 80) / 123.00;
					}


					float a[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };

					if (E2 < 10)
					{
						p3 = a[E2];
					}
					else
					{
						E2 = E2 % 10 + E2 / 10;
						E2 = E2 % 10;


					}
					p3 = a[E2] / 100.0;
					if ((p1 == p2) && (p1 == p3) && (p2 == p3))
					{
						EXP1 = (EXP1 - 0.25 * EXP1);
						if (EXP1 > 600)
						{
							EXP1 = 600;
						}
						if (EXP1 < 0)
						{
							EXP1 = 0;
						}
					}
					else
					{
						P = ((p1 + p2 + p3) / 3 * 1.00);
						if (P >= 0.5)
						{
							HP1 = ceil(HP1 - 0.1 * HP1);
							if (HP1 > 666)
							{
								HP1 = 666;
							}
							if (HP1 < 0)
							{
								HP1 = 0;
							}
							EXP1 = ceil(EXP1 + 0.2 * EXP1);
							if (EXP1 > 600)
							{
								EXP1 = 600;
							}
							if (EXP1 < 0)
							{
								EXP1 = 0;
							}
						}
						else {
							HP1 = ceil(HP1 - 0.15 * HP1);
							if (HP1 > 666)
							{
								HP1 = 666;
							}
							if (HP1 < 0)
							{
								HP1 = 0;
							}
							EXP1 = ceil(EXP1 + 0.15 * EXP1);
							if (EXP1 > 600)
							{
								EXP1 = 600;
							}
							if (EXP1 < 0)
							{
								EXP1 = 0;
							}
						}return HP1 + EXP1 + M1;

					}
				}
				if (M1 > 0)
				{
					if (EXP1 < 300)
					{
						M1 = M1 - 100;
						EXP1 = ceil(EXP1 - 0.1 * EXP1);
						if (EXP1 > 600)
						{
							EXP1 = 600;
						}
						if (EXP1 < 0)
						{
							EXP1 = 0;
						}
					}
					else
					{
						M1 = M1 - 120;
						EXP1 = ceil(EXP1 - 0.1 * EXP1);
						if (EXP1 > 600)
						{
							EXP1 = 600;
						}
						if (EXP1 < 0)
						{
							EXP1 = 0;
						}
					}
				}
				else
				{
					M1 = 0;
					EXP1 = ceil(EXP1 + EXP1 * 0.17);
					if (EXP1 > 600)
					{
						EXP1 = 600;
					}
					if (EXP1 < 0)
					{
						EXP1 = 0;
					}
					HP1 = ceil(HP1 - HP1 * 0.17);
					if (HP1 > 666)
					{
						HP1 = 666;
					}
					if (HP1 < 0)
					{
						HP1 = 0;
					}
					if (EXP1 >= S)
					{
						p2 = 1;
					}
					else
					{
						p2 = ((EXP1 * 1.00) / (S * 1.00) + 80) / 123.00;
					}


					float a[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };

					if (E2 < 10)
					{
						p3 = a[E2];
					}
					else
					{
						E2 = E2 % 10 + E2 / 10;
						E2 = E2 % 10;


					}
					p3 = a[E2] / 100.0;
					if ((p1 == p2) && (p1 == p3) && (p2 == p3))
					{
						EXP1 = ceil(EXP1 - 0.25 * EXP1);
						if (EXP1 > 600)
						{
							EXP1 = 600;
						}
						if (EXP1 < 0)
						{
							EXP1 = 0;
						}
					}
					else
					{
						P = ((p1 + p2 + p3) / 3 * 1.00);
						if (P >= 0.5)
						{
							HP1 = ceil(HP1 - 0.1 * HP1);
							if (HP1 > 666)
							{
								HP1 = 666;
							}
							if (HP1 < 0)
							{
								HP1 = 0;
							}
							EXP1 = ceil(EXP1 + 0.2 * EXP1);
							if (EXP1 > 600)
							{
								EXP1 = 600;
							}
							if (EXP1 < 0)
							{
								EXP1 = 0;
							}
						}
						else {
							HP1 = ceil(HP1 - 0.15 * HP1);
							if (HP1 > 666)
							{
								HP1 = 666;
							}
							if (HP1 < 0)
							{
								HP1 = 0;
							}
							EXP1 = ceil(EXP1 + 0.15 * EXP1);
							if (EXP1 > 600)
							{
								EXP1 = 600;
							}
							if (EXP1 < 0)
							{
								EXP1 = 0;
							}
						}
						return HP1 + EXP1 + M1;

					}
				}
				EXP1 = ceil(EXP1 + EXP1 * 0.17);
				if (EXP1 > 600)
				{
					EXP1 = 600;
				}
				if (EXP1 < 0)
				{
					EXP1 = 0;
				}
				HP1 = ceil(HP1 - HP1 * 0.17);
				if (HP1 > 666)
				{
					HP1 = 666;
				}
				if (HP1 < 0)
				{
					HP1 = 0;
				}
			}


			if (EXP1 >= S)
			{
				p2 = 1;
			}
			else
			{
				p2 = ((EXP1 * 1.00) / (S * 1.00) + 80) / 123.00;
			}


			float a[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };

			if (E2 < 10)
			{
				p3 = a[E2];
			}
			else
			{
				E2 = E2 % 10 + E2 / 10;
				E2 = E2 % 10;


			}
			p3 = a[E2] / 100.0;
			if ((p1 == p2) && (p1 == p3) && (p2 == p3))
			{
				EXP1 = ceil(EXP1 - 0.25 * EXP1);
				if (EXP1 > 600)
				{
					EXP1 = 600;
				}
				if (EXP1 < 0)
				{
					EXP1 = 0;
				}
			}
			else
			{
				P = ((p1 + p2 + p3) / 3 * 1.00);
				if (P >= 0.5)
				{
					HP1 = ceil(HP1 - 0.1 * HP1);
					if (HP1 > 666)
					{
						HP1 = 666;
					}
					if (HP1 < 0)
					{
						HP1 = 0;
					}
					EXP1 = ceil(EXP1 + 0.2 * EXP1);
					if (EXP1 > 600)
					{
						EXP1 = 600;
					}
					if (EXP1 < 0)
					{
						EXP1 = 0;
					}
				}
				else {
					HP1 = ceil(HP1 - 0.15 * HP1);
					if (HP1 > 666)
					{
						HP1 = 666;
					}
					if (HP1 < 0)
					{
						HP1 = 0;
					}
					EXP1 = ceil(EXP1 + 0.15 * EXP1);
					if (EXP1 > 600)
					{
						EXP1 = 600;
					}
					if (EXP1 < 0)
					{
						EXP1 = 0;
					}
				}
			}
		}
	}

	if (HP1 > 666)
	{
		HP1 = 666;
	}
	if (HP1 < 0)
	{
		HP1 = 0;
	}
	if (EXP1 > 600)
	{
		EXP1 = 600;
	}
	if (EXP1 < 0)
	{
		EXP1 = 0;
	}
	if (M1 > 3000)
	{
		M1 = 3000;
	}
	if (M1 < 0)
	{
		M1 = 0;
	}
	return EXP1 + HP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3)
{
	if (E3 < 0 || E3>99)
	{
		return -99;
	}
	else
	{
		if (EXP1 < 0)
		{
			EXP1 = 0;
		}

		if (EXP1 > 600)
		{
			EXP1 = 600;
		}
		if (EXP2 < 0)
		{
			EXP2 = 0;
		}
		if (EXP2 > 600)
		{
			EXP2 = 600;
		}
		if (HP1 < 0)
		{
			HP1 = 0;
		}
		if (HP1 > 666)
		{
			HP1 = 666;
		}
		if (HP2 < 0)
		{
			HP2 = 0;
		}
		if (HP2 > 666)
		{
			HP2 = 666;
		}

		int i, j;
		int taxi[10][10];
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
			}
		}

		int holmes[10][10] =
		{ {0,0,0,0,0,0,0,0,0,0},
		 {0,0,0,0,0,0,0,0,0,0},
		 {0,0,0,0,0,0,0,0,0,0},
		 {0,0,0,0,0,0,0,0,0,0},
		 {0,0,0,0,0,0,0,0,0,0},
		 {0,0,0,0,0,0,0,0,0,0},
		 {0,0,0,0,0,0,0,0,0,0},
		 {0,0,0,0,0,0,0,0,0,0},
		 {0,0,0,0,0,0,0,0,0,0},
		 {0,0,0,0,0,0,0,0,0,0} };
		for (j = 0; j < 10; j++)
		{
			for (i = 0; i < 10; i++)
			{
				int MAX = 0; int startcolum; int startrow;
				for (startcolum = i, startrow = j; startcolum >= 0 && startrow >= 0; startcolum--, startrow--)
				{
					MAX = max(MAX, taxi[startcolum][startrow]);
				}
				for (startcolum = i, startrow = j; startcolum < 10 && startrow < 10; startcolum++, startrow++)
				{
					MAX = max(MAX, taxi[startcolum][startrow]);
				}
				for (startcolum = i, startrow = j; startcolum < 10 && startrow >= 0; startcolum++, startrow--)
				{
					MAX = max(MAX, taxi[startcolum][startrow]);
				}
				for (startcolum = i, startrow = j; startcolum >= 0 && startrow < 10; startcolum--, startrow++)
				{
					MAX = max(MAX, taxi[startcolum][startrow]);
				}
				holmes[i][j] = MAX;
			}
		}
		int x = 0;
		int y = 0;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (taxi[i][j] > E3 * 2)
				{
					x = x + 1;
				}
				else if (taxi[i][j] < (-E3))
				{
					y = y + 1;
				}
			}
		}
		if (x < 10)
		{
			i = x;
		}
		else {
			i = x % 10 + x / 10;
			i = i % 10 + i / 10;
		}
		if (y < 10)
		{
			j = y;
		}
		else {
			j = y % 10 + y / 10;
			j = j % 10 + j / 10;
		}
		if (abs(taxi[i][j]) > abs(holmes[i][j]))
		{
			EXP1 = ceil(EXP1 - EXP1 * 0.12);
			HP1 = ceil(HP1 - HP1 * 0.1);
			EXP2 = ceil(EXP2 - EXP2 * 0.12);
			HP2 = ceil(HP2 - HP2 * 0.1);
			if (EXP1 < 0)
			{
				EXP1 = 0;
			}

			if (EXP1 > 600)
			{
				EXP1 = 600;
			}
			if (EXP2 < 0)
			{
				EXP2 = 0;
			}
			if (EXP2 > 600)
			{
				EXP2 = 600;
			}
			if (HP1 > 666)
			{
				HP1 = 666;
			}
			if (HP2 < 0)
			{
				HP2 = 0;
			}
			if (HP2 > 666)
			{
				HP2 = 666;
			}
			return taxi[i][j];
		}
		else {
			EXP1 = ceil(EXP1 + EXP1 * 0.12);
			HP1 = ceil(HP1 + HP1 * 0.1);
			EXP2 = ceil(EXP2 + EXP2 * 0.12);
			HP2 = ceil(HP2 + HP2 * 0.1);
			if (EXP1 < 0)
			{
				EXP1 = 0;
			}

			if (EXP1 > 600)
			{
				EXP1 = 600;
			}
			if (EXP2 < 0)
			{
				EXP2 = 0;
			}
			if (EXP2 > 600)
			{
				EXP2 = 600;
			}
			if (HP1 > 666)
			{
				HP1 = 666;
			}
			if (HP2 < 0)
			{
				HP2 = 0;
			}
			if (HP2 > 666)
			{
				HP2 = 666;
			}
			return holmes[i][j];
		}

	}
}


// Task 4
int checkPassword(const char* s, const char* email)
{
	char se[100] = {};
	int m = 0;
	int n = strlen(s);

	// Copy chuỗi email vào mảng se
	for (int i = 0; email[i] != '\0'; i++) {
		if (email[i] != '@') {
			se[i] = email[i];
			m++;
		}
		else {
			break;
		}
	}

	if (n < 8) {
		return -1;
	}
	else if (n > 20) {
		return -2;
	}
	else {
		// Kiểm tra mật khẩu
		for (int j = 0; j < n; j++) {
			if (!(s[j] == 64 || s[j] == 35 || s[j] == 37 || s[j] == 36 || s[j] == 33 || (s[j] > 64 && s[j] < 91) || (s[j] > 96 && s[j] < 123) || (s[j] > 47 && s[j] < 58))) {
				return j; // Ký tự không hợp lệ?
			}
		}

		for (int z = 0; z < n - m + 1; z++) {
			int t;
			for (t = 0; t < m; t++) {
				if (se[t] != s[t + z]) {
					break;
				}
			}
			if (t == m) {
				return -(300 + z); // Mật khẩu chứa chuỗi email
			}
		}

		for (int w = 0; w < n - 2; w++) {
			if (s[w] == s[w + 1] && s[w + 1] == s[w + 2]) {
				return -(400 + w); // Mật khẩu chứa 3 ký tự liên tiếp giống nhau
			}
		}
		int q = 0;
		for (int v = 0; v < n; v++) {

			if (s[v] == 64 || s[v] == 35 || s[v] == 37 || s[v] == 33 || s[v] == 36) {
				q++;
			}

		}
		if (q == 0)
		{
			return -5;
		}
		else {
			return -10;
		}
		// Mật khẩu không hợp lệ?

	}

	return -10; // Mật khẩu hợp lệ?
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds)
{
	int l[1000] = { 0 };//tạo mảng lưu số lần giống nhau giữa chuỗi đầu 2,3,4,..,chuỗi 2 với 3,4,5..,chuỗi 3 với 4,5,6
	for (int i = 0; i < num_pwds; i++)
	{
		for (int j = i + 1; j < num_pwds; j++)
		{
			if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
			{
				l[i] = l[i] + 1;
			}
		}
	}

	int max = 0;
	int n = 0;
	int k = 0;
	int flag[1000] = { 0 };
	for (int i = 0; i < num_pwds; i++)//tìm giá trị lớn nhất trong mảng và xem có bao nhiêu giá trị giống giá trị lớn nhất
	{
		if (l[i] > max)
		{
			max = l[i];

		}
	}
	for (int i = 0; i < num_pwds; i++)//tìm giá trị lớn nhất trong mảng và xem có bao nhiêu giá trị giống giá trị lớn nhất
	{
		if (l[i] == max)
		{
			flag[i] = 1;

		}
	}
	string b[1000] = { "\0" };// tạo mảng lưu các giá trị có số lần xuất hiện nhiều nhất
	for (int i = 0; i < 30; i++) {

		if (flag[i] == 1)// gán chuỗi có số lần xuất hiện nhiều nhất bằng nhau vào mảng
		{
			b[i] = arr_pwds[i];
		}

		int size = 0;
		for (int i = 0; i < 30; i++)
		{
			if (b[i].length() > size)
			{
				size = b[i].length();
				k = i;
			}
		}
	}
	return k;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////