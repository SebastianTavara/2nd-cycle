#include "MyForm.h"
#include <ctime>

using namespace std;
using namespace System::Windows::Forms;

void main() {
	srand(time(0));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew GAMEJAM2024II::MyForm());

}