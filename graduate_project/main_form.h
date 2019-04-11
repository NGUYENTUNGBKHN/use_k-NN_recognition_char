#pragma once

#include "NTT_video.h"
#include <opencv2\opencv.hpp>
#include "char_recognized.h"
#include <iostream>
#include <cmath>
#include <math.h>
#include "Robot.h"

namespace graduate_project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::IO;
	using namespace cv;
	using namespace ml;
	using namespace ntt_video;

	/// <summary>
	/// Summary for main_form
	/*-----------CONST-----------------*/
	const int MIN_CONTOUR_AREA = 100;
	const int RESIZED_IMAGE_WIDTH = 20;
	const int RESIZED_IMAGE_HEIGHT = 30;
	/*---------------------------------*/
	/*VARIABLES-----------------------*/
	float time;
	VideoCapture cap;
	Mat video;
	camera cam;
	char_hust char_H;
	char_hust char_U;
	char_hust char_S;
	char_hust char_T;
	//fstream fileOutput;
	volatile bool open_kNN = false;
	bool connecting = false;
	bool chonse_pathTrainClass = false;
	bool chonse_pathTrainimages = false;
	char *trainClassification;
	char *trainImages;
	bool inc, dec;
	/*--------------------------------*/
	/// </summary>
	public ref class main_form : public System::Windows::Forms::Form
	{
	public:
		main_form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~main_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_exit;
	private: System::Windows::Forms::PictureBox^  pBox_camDisplay;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Timer^  timer_camera;
	private: System::Windows::Forms::Button^  btn_play;
	private: System::Windows::Forms::Button^  btn_stop;
	private: System::Windows::Forms::ComboBox^  cBox_chosenDeviceCam;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::IO::Ports::SerialPort^  serialPortCom;

	private: System::Windows::Forms::Button^  btnTrain;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  Class;
	private: System::Windows::Forms::TextBox^  tBoxImages;
	private: System::Windows::Forms::TextBox^  tBoxClass;
	private: System::Windows::Forms::Button^  btnImages;
	private: System::Windows::Forms::Button^  btnClassification;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Button^  btnProcess;
	private: System::Windows::Forms::Button^  btnConnect;
	private: System::Windows::Forms::GroupBox^  RS232;

	private: System::Windows::Forms::ComboBox^  cBoxCom;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  btnDisconnect;
	private: System::Windows::Forms::ProgressBar^  proBar;
	private: System::Windows::Forms::Timer^  timer_com;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::TextBox^  textBoxZ;
	private: System::Windows::Forms::TextBox^  textBoxY;
	private: System::Windows::Forms::TextBox^  textBoxX;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::GroupBox^  gBoxControlRobot;

	private: System::Windows::Forms::Label^  labelDof3;
	private: System::Windows::Forms::Label^  labelDof2;
	private: System::Windows::Forms::Label^  labelDof1;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TrackBar^  tBarDof3;
	private: System::Windows::Forms::TrackBar^  tBarDof2;
	private: System::Windows::Forms::TrackBar^  tBarDof1;
	private: System::Windows::Forms::Timer^  timer_controlRobot;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::Button^  btnReverseKinetic;
	private: System::Windows::Forms::TextBox^  textBoxZ_RK;
	private: System::Windows::Forms::TextBox^  textBoxY_RK;
	private: System::Windows::Forms::TextBox^  textBoxX_RK;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Timer^  timerRobot;
	private: System::Windows::Forms::TextBox^  text;
	private: System::Windows::Forms::Button^  btnTest;
	private: System::Windows::Forms::TextBox^  text2;
	private: System::Windows::Forms::TextBox^  text3;
	private: System::Windows::Forms::TextBox^  debug;






	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(main_form::typeid));
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->pBox_camDisplay = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->timer_camera = (gcnew System::Windows::Forms::Timer(this->components));
			this->btn_play = (gcnew System::Windows::Forms::Button());
			this->btn_stop = (gcnew System::Windows::Forms::Button());
			this->cBox_chosenDeviceCam = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->serialPortCom = (gcnew System::IO::Ports::SerialPort(this->components));
			this->btnTrain = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Class = (gcnew System::Windows::Forms::Label());
			this->tBoxImages = (gcnew System::Windows::Forms::TextBox());
			this->tBoxClass = (gcnew System::Windows::Forms::TextBox());
			this->btnImages = (gcnew System::Windows::Forms::Button());
			this->btnClassification = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->btnProcess = (gcnew System::Windows::Forms::Button());
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->RS232 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->proBar = (gcnew System::Windows::Forms::ProgressBar());
			this->cBoxCom = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnDisconnect = (gcnew System::Windows::Forms::Button());
			this->timer_com = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->btnTest = (gcnew System::Windows::Forms::Button());
			this->textBoxZ = (gcnew System::Windows::Forms::TextBox());
			this->textBoxY = (gcnew System::Windows::Forms::TextBox());
			this->textBoxX = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->gBoxControlRobot = (gcnew System::Windows::Forms::GroupBox());
			this->labelDof3 = (gcnew System::Windows::Forms::Label());
			this->labelDof2 = (gcnew System::Windows::Forms::Label());
			this->labelDof1 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tBarDof3 = (gcnew System::Windows::Forms::TrackBar());
			this->tBarDof2 = (gcnew System::Windows::Forms::TrackBar());
			this->tBarDof1 = (gcnew System::Windows::Forms::TrackBar());
			this->timer_controlRobot = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->btnReverseKinetic = (gcnew System::Windows::Forms::Button());
			this->textBoxZ_RK = (gcnew System::Windows::Forms::TextBox());
			this->textBoxY_RK = (gcnew System::Windows::Forms::TextBox());
			this->textBoxX_RK = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->timerRobot = (gcnew System::Windows::Forms::Timer(this->components));
			this->text = (gcnew System::Windows::Forms::TextBox());
			this->text2 = (gcnew System::Windows::Forms::TextBox());
			this->text3 = (gcnew System::Windows::Forms::TextBox());
			this->debug = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBox_camDisplay))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->RS232->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->gBoxControlRobot->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tBarDof3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tBarDof2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tBarDof1))->BeginInit();
			this->groupBox6->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn_exit
			// 
			this->btn_exit->Location = System::Drawing::Point(1105, 411);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(100, 87);
			this->btn_exit->TabIndex = 0;
			this->btn_exit->Text = L"EXIT";
			this->btn_exit->UseVisualStyleBackColor = true;
			this->btn_exit->Click += gcnew System::EventHandler(this, &main_form::btn_exit_Click);
			// 
			// pBox_camDisplay
			// 
			this->pBox_camDisplay->Location = System::Drawing::Point(6, 16);
			this->pBox_camDisplay->Name = L"pBox_camDisplay";
			this->pBox_camDisplay->Size = System::Drawing::Size(647, 477);
			this->pBox_camDisplay->TabIndex = 1;
			this->pBox_camDisplay->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->pBox_camDisplay);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(659, 499);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"CAMERA";
			// 
			// timer_camera
			// 
			this->timer_camera->Interval = 10;
			this->timer_camera->Tick += gcnew System::EventHandler(this, &main_form::timer_camera_Tick);
			// 
			// btn_play
			// 
			this->btn_play->Location = System::Drawing::Point(165, 11);
			this->btn_play->Name = L"btn_play";
			this->btn_play->Size = System::Drawing::Size(75, 23);
			this->btn_play->TabIndex = 3;
			this->btn_play->Text = L"Play";
			this->btn_play->UseVisualStyleBackColor = true;
			this->btn_play->Click += gcnew System::EventHandler(this, &main_form::btn_play_Click);
			// 
			// btn_stop
			// 
			this->btn_stop->Location = System::Drawing::Point(165, 40);
			this->btn_stop->Name = L"btn_stop";
			this->btn_stop->Size = System::Drawing::Size(75, 23);
			this->btn_stop->TabIndex = 4;
			this->btn_stop->Text = L"Stop";
			this->btn_stop->UseVisualStyleBackColor = true;
			this->btn_stop->Click += gcnew System::EventHandler(this, &main_form::btn_stop_Click);
			// 
			// cBox_chosenDeviceCam
			// 
			this->cBox_chosenDeviceCam->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) { L"LAP", L"USER" });
			this->cBox_chosenDeviceCam->FormattingEnabled = true;
			this->cBox_chosenDeviceCam->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"MAIN_1", L"MAIN_2" });
			this->cBox_chosenDeviceCam->Location = System::Drawing::Point(74, 13);
			this->cBox_chosenDeviceCam->Name = L"cBox_chosenDeviceCam";
			this->cBox_chosenDeviceCam->Size = System::Drawing::Size(85, 21);
			this->cBox_chosenDeviceCam->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"DEVICE";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->cBox_chosenDeviceCam);
			this->groupBox2->Controls->Add(this->btn_stop);
			this->groupBox2->Controls->Add(this->btn_play);
			this->groupBox2->Location = System::Drawing::Point(695, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(252, 76);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Control Camera";
			// 
			// btnTrain
			// 
			this->btnTrain->Location = System::Drawing::Point(165, 19);
			this->btnTrain->Name = L"btnTrain";
			this->btnTrain->Size = System::Drawing::Size(75, 23);
			this->btnTrain->TabIndex = 9;
			this->btnTrain->Text = L"Train";
			this->btnTrain->UseVisualStyleBackColor = true;
			this->btnTrain->Click += gcnew System::EventHandler(this, &main_form::btnTrain_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->Class);
			this->groupBox3->Controls->Add(this->tBoxImages);
			this->groupBox3->Controls->Add(this->tBoxClass);
			this->groupBox3->Controls->Add(this->btnImages);
			this->groupBox3->Controls->Add(this->btnClassification);
			this->groupBox3->Controls->Add(this->btnTrain);
			this->groupBox3->Location = System::Drawing::Point(953, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(252, 121);
			this->groupBox3->TabIndex = 10;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Trainning char";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 95);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 13);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Images File";
			// 
			// Class
			// 
			this->Class->AutoSize = true;
			this->Class->Location = System::Drawing::Point(16, 69);
			this->Class->Name = L"Class";
			this->Class->Size = System::Drawing::Size(51, 13);
			this->Class->TabIndex = 14;
			this->Class->Text = L"Class File";
			// 
			// tBoxImages
			// 
			this->tBoxImages->Location = System::Drawing::Point(74, 92);
			this->tBoxImages->Name = L"tBoxImages";
			this->tBoxImages->Size = System::Drawing::Size(132, 20);
			this->tBoxImages->TabIndex = 13;
			// 
			// tBoxClass
			// 
			this->tBoxClass->Location = System::Drawing::Point(74, 66);
			this->tBoxClass->Name = L"tBoxClass";
			this->tBoxClass->Size = System::Drawing::Size(132, 20);
			this->tBoxClass->TabIndex = 12;
			// 
			// btnImages
			// 
			this->btnImages->Location = System::Drawing::Point(212, 92);
			this->btnImages->Name = L"btnImages";
			this->btnImages->Size = System::Drawing::Size(28, 23);
			this->btnImages->TabIndex = 11;
			this->btnImages->Text = L"...";
			this->btnImages->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnImages->UseVisualStyleBackColor = true;
			this->btnImages->Click += gcnew System::EventHandler(this, &main_form::btnImages_Click);
			// 
			// btnClassification
			// 
			this->btnClassification->Location = System::Drawing::Point(212, 63);
			this->btnClassification->Name = L"btnClassification";
			this->btnClassification->Size = System::Drawing::Size(28, 23);
			this->btnClassification->TabIndex = 10;
			this->btnClassification->Text = L"...";
			this->btnClassification->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnClassification->UseVisualStyleBackColor = true;
			this->btnClassification->Click += gcnew System::EventHandler(this, &main_form::btnClassification_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->btnProcess);
			this->groupBox4->Location = System::Drawing::Point(695, 94);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(252, 100);
			this->groupBox4->TabIndex = 11;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Process";
			// 
			// btnProcess
			// 
			this->btnProcess->Location = System::Drawing::Point(171, 19);
			this->btnProcess->Name = L"btnProcess";
			this->btnProcess->Size = System::Drawing::Size(75, 23);
			this->btnProcess->TabIndex = 0;
			this->btnProcess->Text = L"Process";
			this->btnProcess->UseVisualStyleBackColor = true;
			this->btnProcess->Click += gcnew System::EventHandler(this, &main_form::btnProcess_Click);
			// 
			// btnConnect
			// 
			this->btnConnect->Location = System::Drawing::Point(165, 24);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(75, 23);
			this->btnConnect->TabIndex = 12;
			this->btnConnect->Text = L"Connect";
			this->btnConnect->UseVisualStyleBackColor = true;
			this->btnConnect->Click += gcnew System::EventHandler(this, &main_form::btnConnect_Click);
			// 
			// RS232
			// 
			this->RS232->Controls->Add(this->label4);
			this->RS232->Controls->Add(this->proBar);
			this->RS232->Controls->Add(this->cBoxCom);
			this->RS232->Controls->Add(this->label3);
			this->RS232->Controls->Add(this->btnDisconnect);
			this->RS232->Controls->Add(this->btnConnect);
			this->RS232->Location = System::Drawing::Point(695, 200);
			this->RS232->Name = L"RS232";
			this->RS232->Size = System::Drawing::Size(252, 100);
			this->RS232->TabIndex = 13;
			this->RS232->TabStop = false;
			this->RS232->Text = L"Communication";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(61, 65);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 16;
			this->label4->Text = L"status";
			// 
			// proBar
			// 
			this->proBar->Location = System::Drawing::Point(102, 60);
			this->proBar->Name = L"proBar";
			this->proBar->Size = System::Drawing::Size(53, 23);
			this->proBar->TabIndex = 1;
			// 
			// cBoxCom
			// 
			this->cBoxCom->FormattingEnabled = true;
			this->cBoxCom->Location = System::Drawing::Point(49, 26);
			this->cBoxCom->Name = L"cBoxCom";
			this->cBoxCom->Size = System::Drawing::Size(106, 21);
			this->cBoxCom->TabIndex = 15;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 29);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"COM";
			// 
			// btnDisconnect
			// 
			this->btnDisconnect->Location = System::Drawing::Point(165, 60);
			this->btnDisconnect->Name = L"btnDisconnect";
			this->btnDisconnect->Size = System::Drawing::Size(75, 23);
			this->btnDisconnect->TabIndex = 13;
			this->btnDisconnect->Text = L"Disconnect";
			this->btnDisconnect->UseVisualStyleBackColor = true;
			this->btnDisconnect->Click += gcnew System::EventHandler(this, &main_form::btnDisconnect_Click);
			// 
			// timer_com
			// 
			this->timer_com->Interval = 10;
			this->timer_com->Tick += gcnew System::EventHandler(this, &main_form::timer_com_Tick);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->btnTest);
			this->groupBox5->Controls->Add(this->textBoxZ);
			this->groupBox5->Controls->Add(this->textBoxY);
			this->groupBox5->Controls->Add(this->textBoxX);
			this->groupBox5->Controls->Add(this->label7);
			this->groupBox5->Controls->Add(this->label6);
			this->groupBox5->Controls->Add(this->label5);
			this->groupBox5->Location = System::Drawing::Point(953, 139);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(117, 161);
			this->groupBox5->TabIndex = 14;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Pros Kinetic";
			// 
			// btnTest
			// 
			this->btnTest->Location = System::Drawing::Point(15, 101);
			this->btnTest->Name = L"btnTest";
			this->btnTest->Size = System::Drawing::Size(75, 23);
			this->btnTest->TabIndex = 1;
			this->btnTest->Text = L"button1";
			this->btnTest->UseVisualStyleBackColor = true;
			this->btnTest->Click += gcnew System::EventHandler(this, &main_form::btnTest_Click);
			// 
			// textBoxZ
			// 
			this->textBoxZ->Location = System::Drawing::Point(29, 75);
			this->textBoxZ->Name = L"textBoxZ";
			this->textBoxZ->Size = System::Drawing::Size(59, 20);
			this->textBoxZ->TabIndex = 20;
			// 
			// textBoxY
			// 
			this->textBoxY->Location = System::Drawing::Point(29, 49);
			this->textBoxY->Name = L"textBoxY";
			this->textBoxY->Size = System::Drawing::Size(59, 20);
			this->textBoxY->TabIndex = 19;
			// 
			// textBoxX
			// 
			this->textBoxX->Location = System::Drawing::Point(29, 23);
			this->textBoxX->Name = L"textBoxX";
			this->textBoxX->Size = System::Drawing::Size(59, 20);
			this->textBoxX->TabIndex = 1;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 75);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(14, 13);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Z";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 52);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(14, 13);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Y";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 26);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(14, 13);
			this->label5->TabIndex = 16;
			this->label5->Text = L"X";
			// 
			// gBoxControlRobot
			// 
			this->gBoxControlRobot->Controls->Add(this->labelDof3);
			this->gBoxControlRobot->Controls->Add(this->labelDof2);
			this->gBoxControlRobot->Controls->Add(this->labelDof1);
			this->gBoxControlRobot->Controls->Add(this->label10);
			this->gBoxControlRobot->Controls->Add(this->label9);
			this->gBoxControlRobot->Controls->Add(this->label8);
			this->gBoxControlRobot->Controls->Add(this->tBarDof3);
			this->gBoxControlRobot->Controls->Add(this->tBarDof2);
			this->gBoxControlRobot->Controls->Add(this->tBarDof1);
			this->gBoxControlRobot->Location = System::Drawing::Point(697, 306);
			this->gBoxControlRobot->Name = L"gBoxControlRobot";
			this->gBoxControlRobot->Size = System::Drawing::Size(385, 192);
			this->gBoxControlRobot->TabIndex = 15;
			this->gBoxControlRobot->TabStop = false;
			this->gBoxControlRobot->Text = L"Control robot";
			// 
			// labelDof3
			// 
			this->labelDof3->AutoSize = true;
			this->labelDof3->Location = System::Drawing::Point(318, 133);
			this->labelDof3->Name = L"labelDof3";
			this->labelDof3->Size = System::Drawing::Size(0, 13);
			this->labelDof3->TabIndex = 26;
			// 
			// labelDof2
			// 
			this->labelDof2->AutoSize = true;
			this->labelDof2->Location = System::Drawing::Point(318, 82);
			this->labelDof2->Name = L"labelDof2";
			this->labelDof2->Size = System::Drawing::Size(0, 13);
			this->labelDof2->TabIndex = 25;
			// 
			// labelDof1
			// 
			this->labelDof1->AutoSize = true;
			this->labelDof1->Location = System::Drawing::Point(318, 31);
			this->labelDof1->Name = L"labelDof1";
			this->labelDof1->Size = System::Drawing::Size(0, 13);
			this->labelDof1->TabIndex = 24;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(10, 133);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(30, 13);
			this->label10->TabIndex = 23;
			this->label10->Text = L"Dof3";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(10, 82);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(30, 13);
			this->label9->TabIndex = 22;
			this->label9->Text = L"Dof2";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(10, 31);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(30, 13);
			this->label8->TabIndex = 21;
			this->label8->Text = L"Dof1";
			// 
			// tBarDof3
			// 
			this->tBarDof3->Location = System::Drawing::Point(46, 133);
			this->tBarDof3->Maximum = 180;
			this->tBarDof3->Name = L"tBarDof3";
			this->tBarDof3->Size = System::Drawing::Size(266, 45);
			this->tBarDof3->TabIndex = 18;
			this->tBarDof3->ValueChanged += gcnew System::EventHandler(this, &main_form::valueChangeDof3);
			// 
			// tBarDof2
			// 
			this->tBarDof2->Location = System::Drawing::Point(46, 82);
			this->tBarDof2->Maximum = 180;
			this->tBarDof2->Name = L"tBarDof2";
			this->tBarDof2->Size = System::Drawing::Size(266, 45);
			this->tBarDof2->TabIndex = 17;
			this->tBarDof2->ValueChanged += gcnew System::EventHandler(this, &main_form::valueChangeDof2);
			// 
			// tBarDof1
			// 
			this->tBarDof1->Location = System::Drawing::Point(46, 31);
			this->tBarDof1->Maximum = 180;
			this->tBarDof1->Name = L"tBarDof1";
			this->tBarDof1->Size = System::Drawing::Size(266, 45);
			this->tBarDof1->TabIndex = 16;
			this->tBarDof1->ValueChanged += gcnew System::EventHandler(this, &main_form::valueChangeDof1);
			// 
			// timer_controlRobot
			// 
			this->timer_controlRobot->Interval = 10;
			this->timer_controlRobot->Tick += gcnew System::EventHandler(this, &main_form::timer_controlRobot_Tick);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->btnReverseKinetic);
			this->groupBox6->Controls->Add(this->textBoxZ_RK);
			this->groupBox6->Controls->Add(this->textBoxY_RK);
			this->groupBox6->Controls->Add(this->textBoxX_RK);
			this->groupBox6->Controls->Add(this->label11);
			this->groupBox6->Controls->Add(this->label12);
			this->groupBox6->Controls->Add(this->label13);
			this->groupBox6->Location = System::Drawing::Point(1076, 139);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(129, 161);
			this->groupBox6->TabIndex = 21;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Reverse Kinetic";
			// 
			// btnReverseKinetic
			// 
			this->btnReverseKinetic->Location = System::Drawing::Point(6, 101);
			this->btnReverseKinetic->Name = L"btnReverseKinetic";
			this->btnReverseKinetic->Size = System::Drawing::Size(111, 23);
			this->btnReverseKinetic->TabIndex = 1;
			this->btnReverseKinetic->Text = L"Reverse Kinetic";
			this->btnReverseKinetic->UseVisualStyleBackColor = true;
			this->btnReverseKinetic->Click += gcnew System::EventHandler(this, &main_form::btnReverseKinetic_Click);
			// 
			// textBoxZ_RK
			// 
			this->textBoxZ_RK->Location = System::Drawing::Point(29, 75);
			this->textBoxZ_RK->Name = L"textBoxZ_RK";
			this->textBoxZ_RK->Size = System::Drawing::Size(59, 20);
			this->textBoxZ_RK->TabIndex = 20;
			// 
			// textBoxY_RK
			// 
			this->textBoxY_RK->Location = System::Drawing::Point(29, 49);
			this->textBoxY_RK->Name = L"textBoxY_RK";
			this->textBoxY_RK->Size = System::Drawing::Size(59, 20);
			this->textBoxY_RK->TabIndex = 19;
			// 
			// textBoxX_RK
			// 
			this->textBoxX_RK->Location = System::Drawing::Point(29, 23);
			this->textBoxX_RK->Name = L"textBoxX_RK";
			this->textBoxX_RK->Size = System::Drawing::Size(59, 20);
			this->textBoxX_RK->TabIndex = 1;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(12, 75);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(14, 13);
			this->label11->TabIndex = 18;
			this->label11->Text = L"Z";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(12, 52);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(14, 13);
			this->label12->TabIndex = 17;
			this->label12->Text = L"Y";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(12, 26);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(14, 13);
			this->label13->TabIndex = 16;
			this->label13->Text = L"X";
			// 
			// timerRobot
			// 
			this->timerRobot->Interval = 10;
			this->timerRobot->Tick += gcnew System::EventHandler(this, &main_form::timerRobot_Tick);
			// 
			// text
			// 
			this->text->Location = System::Drawing::Point(1088, 306);
			this->text->Name = L"text";
			this->text->Size = System::Drawing::Size(100, 20);
			this->text->TabIndex = 27;
			// 
			// text2
			// 
			this->text2->Location = System::Drawing::Point(1088, 334);
			this->text2->Name = L"text2";
			this->text2->Size = System::Drawing::Size(100, 20);
			this->text2->TabIndex = 28;
			// 
			// text3
			// 
			this->text3->Location = System::Drawing::Point(1088, 362);
			this->text3->Name = L"text3";
			this->text3->Size = System::Drawing::Size(100, 20);
			this->text3->TabIndex = 29;
			// 
			// debug
			// 
			this->debug->Location = System::Drawing::Point(1091, 388);
			this->debug->Name = L"debug";
			this->debug->Size = System::Drawing::Size(100, 20);
			this->debug->TabIndex = 2;
			// 
			// main_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1217, 523);
			this->Controls->Add(this->debug);
			this->Controls->Add(this->text3);
			this->Controls->Add(this->text2);
			this->Controls->Add(this->text);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->gBoxControlRobot);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->RS232);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->btn_exit);
			this->HelpButton = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"main_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PROJECT CHARACTERS RECOGNITION";
			this->Load += gcnew System::EventHandler(this, &main_form::main_form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pBox_camDisplay))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->RS232->ResumeLayout(false);
			this->RS232->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->gBoxControlRobot->ResumeLayout(false);
			this->gBoxControlRobot->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tBarDof3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tBarDof2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tBarDof1))->EndInit();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void main_form_Load(System::Object^  sender, System::EventArgs^  e) {
		btnTrain->Enabled = false;
		btnProcess->Enabled = false;
		gBoxControlRobot->Enabled = false;
		timer_com->Start();
		timer_controlRobot->Start();
	}
	private: void char_Recognized(Mat image_test, Mat matTrainImageInits, Mat matClassificationInits) {
		
		std::vector<ContourWithData> allContoursWithData;
		std::vector<ContourWithData> validContoursWithData;

		// init Knn
		Ptr<ml::KNearest> kNearest(ml::KNearest::create());
		// init train
		kNearest->train(matTrainImageInits, ml::ROW_SAMPLE, matClassificationInits);
		/*test run*/
		if (image_test.empty())
		{
			MessageBox::Show("Can't show images, try again !!!", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		Mat matGrayscale;
		Mat matBlurred;
		Mat matThresh;
		Mat matThreshCopy;
		Mat matCanny;


		// convert image origin into gray image
		cvtColor(image_test, matGrayscale, CV_BGR2GRAY);

		// smoothing
		GaussianBlur(matGrayscale, matBlurred, cv::Size(5, 5), 0);

		Canny(matBlurred, matCanny, 100, 3);
		imshow("oka", matCanny);
		// create mat thresh
		adaptiveThreshold(matBlurred, matThresh, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 11, 2);
		//threshold(matBlurred, matThresh, 128, 255, THRESH_BINARY_INV);
		//imshow("okaa", matThresh);
		matThreshCopy = matThresh.clone();

		std::vector<std::vector<cv::Point> > ptContours;
		std::vector<Vec4i> v4iHierarchy;

		findContours(matCanny, ptContours, v4iHierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
		//findContours(matCanny, ptContours, v4iHierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

		for (int i = 0; i < ptContours.size(); i++)
		{
			ContourWithData contourWithData;
			contourWithData.ptContour = ptContours[i];
			contourWithData.boundingRect = boundingRect(contourWithData.ptContour);
			contourWithData.fltArea = contourArea(contourWithData.ptContour);
			allContoursWithData.push_back(contourWithData);
		}

		for (int i = 0; i < allContoursWithData.size(); i++)
		{
			if (allContoursWithData[i].checkIfContourIsValid())
			{
				validContoursWithData.push_back(allContoursWithData[i]);
			}
		}

		sort(validContoursWithData.begin(), validContoursWithData.end(), ContourWithData::sortByBoundingRectXPosition);

		//std::string strFinalString;
		//char hust[4];
		//char_hust char_H;
		//char_hust char_U;
		//char_hust char_S;
		//char_hust char_T;
		std::cout << "***************************" << std::endl;
		for (int i = 0; i < validContoursWithData.size(); i++)
		{

			//rectangle(image_test, validContoursWithData[i].boundingRect, Scalar(0, 255, 0), 2);

			Mat matROI = matThresh(validContoursWithData[i].boundingRect);

			Mat matROIResized;
			resize(matROI, matROIResized, cv::Size(RESIZED_IMAGE_WIDTH, RESIZED_IMAGE_HEIGHT));

			Mat matROIFloat;
			matROIResized.convertTo(matROIFloat, CV_32FC1);

			Mat matROIFlattenedFloat = matROIFloat.reshape(1, 1);

			Mat matCurrentChar(0, 0, CV_32F);

			kNearest->findNearest(matROIFlattenedFloat, 1, matCurrentChar);

			float fltCurrentChar = (float)matCurrentChar.at<float>(0, 0);
			
			if (validContoursWithData[i].boundingRect.width < 60 && validContoursWithData[i].boundingRect.height < 60
				&& validContoursWithData[i].boundingRect.width > 30 && validContoursWithData[i].boundingRect.height > 30)
			{
				//strFinalString = strFinalString + char(int(fltCurrentChar));
				rectangle(image_test, validContoursWithData[i].boundingRect, Scalar(0, 255, 0), 2);
				std::cout << "toa do " << (char)fltCurrentChar << "  ( " << validContoursWithData[i].boundingRect.x
					<< " : " << validContoursWithData[i].boundingRect.y << " ) " << validContoursWithData[i].boundingRect.height
					<< " , " << validContoursWithData[i].boundingRect.width << "\n";
				switch (char(int(fltCurrentChar)))
				{
				case 'H':
					char_H.object	= char(int(fltCurrentChar));
					char_H.x		= validContoursWithData[i].boundingRect.x;
					char_H.y		= validContoursWithData[i].boundingRect.y;
					char_H.height	= validContoursWithData[i].boundingRect.height;
					char_H.width	= validContoursWithData[i].boundingRect.width;
					char_H.detect	= true;
					break;
				case 'U':
					char_U.object = char(int(fltCurrentChar));
					char_U.x = validContoursWithData[i].boundingRect.x;
					char_U.y = validContoursWithData[i].boundingRect.y;
					char_U.height = validContoursWithData[i].boundingRect.height;
					char_U.width = validContoursWithData[i].boundingRect.width;
					char_U.detect = true;
					break;
				case 'S':
					char_S.object = char(int(fltCurrentChar));
					char_S.x = validContoursWithData[i].boundingRect.x;
					char_S.y = validContoursWithData[i].boundingRect.y;
					char_S.height = validContoursWithData[i].boundingRect.height;
					char_S.width = validContoursWithData[i].boundingRect.width;
					char_S.detect = true;
					break;
				case 'T':
					char_T.object = char(int(fltCurrentChar));
					char_T.x = validContoursWithData[i].boundingRect.x;
					char_T.y = validContoursWithData[i].boundingRect.y;
					char_T.height = validContoursWithData[i].boundingRect.height;
					char_T.width = validContoursWithData[i].boundingRect.width;
					char_T.detect = true;
					break;
				}
			}
		}
		if (char_H.detect == true)
		{
			std::cout << "chu " << char_H.object << ", x =" << char_H.x << ", y=" << char_H.y <<
				", height=" << char_H.height << ", width=" << char_H.width << std::endl;
		}

		imshow("origin", image_test);
	}

	private: System::Void timer_camera_Tick(System::Object^  sender, System::EventArgs^  e) {
		main_func();
	}
	private: void main_func() {
		cap.read(video);
		pBox_camDisplay->Size = System::Drawing::Size(video.cols, video.rows);
		pBox_camDisplay->Image = cam.Show(video);
		if (open_kNN == true)
		{
			open_kNN = false;
			/* create mat classfication*/
			Mat matClassificationInits;
			FileStorage fsClassifications("classifications.xml", FileStorage::READ);

			if (fsClassifications.isOpened() == false)
			{
				//std::cout << "error Classification.xml \n" << std::endl;
				MessageBox::Show("Don't open Classification.xml , try again !!!", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			// push in Mat
			fsClassifications["classifications"] >> matClassificationInits;
			fsClassifications.release();

			/*create mat train images*/
			Mat matTrainImageInits;
			FileStorage fsTrainImages("images.xml", FileStorage::READ);

			if (fsTrainImages.isOpened() == false)
			{
				//std::cout << "error images.xml \n" << std::endl;
				MessageBox::Show("Don't open images.xml , try again !!!", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			fsTrainImages["images"] >> matTrainImageInits;
			fsTrainImages.release();
			char_Recognized(video, matTrainImageInits, matClassificationInits);
		}
		waitKey(10);
	}
	private: System::Void btn_play_Click(System::Object^  sender, System::EventArgs^  e) {

		if (cBox_chosenDeviceCam->Text == "MAIN_1")
		{
			cap.open(0);
		}
		else if (cBox_chosenDeviceCam->Text == "MAIN_2")
		{
			cap.open(1);
		}
		if (cap.isOpened())
		{
			timer_camera->Start();
			btnProcess->Enabled = true;
		}
		else
		{
			MessageBox::Show("Error camera or not yet chosen device camera, try again !!!","Error",
								MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
	}
	private: System::Void btn_stop_Click(System::Object^  sender, System::EventArgs^  e) {
		pBox_camDisplay->Image = Image::FromFile("icon/pause.bmp");
		timer_camera->Stop();
		btnProcess->Enabled = false;
	}

	private: System::Void btn_exit_Click(System::Object^  sender, System::EventArgs^  e) {
		if (MessageBox::Show("Are you sure?", "Question", 
			MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::Yes)
		{
			Application::Exit();
		}
	}
	/*Function train images */
	private: void trainImage(char *path_imagesTrain, char *path_trainClassification, char *path_trainImages) {
		Mat imgTrainingNumbers;         
		Mat imgGrayscale;  
		Mat imgBlurred; 
		Mat imgThresh;
		Mat imgThreshCopy;
		Mat imgCanny;

		std::vector<std::vector<cv::Point> > ptContours; 
		std::vector<Vec4i> v4iHierarchy;   

		Mat matClassificationInts;      

		Mat matTrainingImagesAsFlattenedFloats;

		std::vector<int> intValidChars = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
			'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
			'U', 'V', 'W', 'X', 'Y', 'Z', '-'};
		
		imgTrainingNumbers = imread(path_imagesTrain);
		if (imgTrainingNumbers.empty()) {                              
			//std::cout << "error: image not read from file\n\n";
			MessageBox::Show("error: image not read from file, try again !!!", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		cvtColor(imgTrainingNumbers, imgGrayscale, CV_BGR2GRAY); 

		GaussianBlur(imgGrayscale, imgBlurred, cv::Size(5, 5),0);   
													
		adaptiveThreshold(imgBlurred, imgThresh, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 11, 2);
		Canny(imgBlurred, imgCanny, 20, 3,3);
		imshow("oka", imgCanny);
		//imshow("imgThresh", imgThresh);       

		imgThreshCopy = imgThresh.clone();       

		findContours(imgCanny, ptContours, v4iHierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

		for (int i = 0; i < ptContours.size(); i++)
		{    
			if (contourArea(ptContours[i]) > MIN_CONTOUR_AREA) 
			{               
				Rect boundingRect = cv::boundingRect(ptContours[i]);             

				rectangle(imgTrainingNumbers, boundingRect, Scalar(0, 0, 255), 2);     

				Mat matROI = imgThresh(boundingRect);        

				Mat matROIResized;
				resize(matROI, matROIResized, cv::Size(RESIZED_IMAGE_WIDTH, RESIZED_IMAGE_HEIGHT));   

				imshow("matROI", matROI);                             
				imshow("matROIResized", matROIResized);                 
				imshow("imgTrainingNumbers", imgTrainingNumbers);     

				int intChar = waitKey(0);        

				if (intChar == 27) {               
				}
				else if (find(intValidChars.begin(), intValidChars.end(), intChar) != intValidChars.end()) 
				{     
					
					matClassificationInts.push_back(intChar);       

					Mat matImageFloat;                          
					matROIResized.convertTo(matImageFloat, CV_32FC1);      

					Mat matImageFlattenedFloat = matImageFloat.reshape(1, 1);       

					matTrainingImagesAsFlattenedFloats.push_back(matImageFlattenedFloat);      
																								
				}  
			}   
		}   

		std::cout << "training complete\n\n";

		FileStorage fsClassifications(path_trainClassification, FileStorage::WRITE);

		if (fsClassifications.isOpened() == false)
		{                                                       
			//std::cout << "error, unable to open training classifications file, exiting program\n\n";
			MessageBox::Show("error, unable to open training classifications file, exiting program !!!", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			//return(0);                                        
		}

		fsClassifications << "classifications" << matClassificationInts;      
		fsClassifications.release();                                            																	

		FileStorage fsTrainingImages(path_trainImages, FileStorage::WRITE);

		if (fsTrainingImages.isOpened() == false) {                                                
			//std::cout << "error, unable to open training images file, exiting program\n\n";
			MessageBox::Show("error, unable to open training images file, exiting program !!!", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);                                                                     
		}

		fsTrainingImages << "images" << matTrainingImagesAsFlattenedFloats;    
		fsTrainingImages.release();                                            
		MessageBox::Show("Training Done !!!", "Notificaiton", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void btnTrain_Click(System::Object^  sender, System::EventArgs^  e) {
		
		OpenFileDialog^ openfile = gcnew OpenFileDialog;
		openfile->Filter = "Windows Bitmap|*.bmp|JPEG Image|*.jpg|All Files|*.*";
		if (openfile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			char *fileName = (char*)Marshal::StringToHGlobalAnsi(openfile->FileName).ToPointer();
			trainImage(fileName,trainClassification, trainImages);
		}
	}
	private: System::Void btnProcess_Click(System::Object^  sender, System::EventArgs^  e) {
		open_kNN = true;
		timer_camera->Start();
	}
	private: System::Void btnConnect_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!serialPortCom->IsOpen && cBoxCom->Text != "")
		{
			gBoxControlRobot->Enabled = true;
			connecting = true;
			serialPortCom->PortName = cBoxCom->Text;
			serialPortCom->Open();
			btnConnect->Enabled = false;
			btnDisconnect->Enabled = true;
			proBar->Value = 100;
		}
	}
	private: System::Void btnDisconnect_Click(System::Object^  sender, System::EventArgs^  e) {
		if (cBoxCom->Text != "")
		{
			gBoxControlRobot->Enabled = false;
			connecting = false;
			serialPortCom->Close();
			btnDisconnect->Enabled = false;
			btnConnect->Enabled = true;
			proBar->Value = 0;
		}
	}
	private: System::Void timer_com_Tick(System::Object^  sender, System::EventArgs^  e) {
		cBoxCom->Text = "";
		cBoxCom->DataSource = SerialPort::GetPortNames();
		if (chonse_pathTrainClass && chonse_pathTrainimages)
		{
			btnTrain->Enabled = true;
		}
	}
	private: System::Void btnClassification_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openfile_trainClassification = gcnew OpenFileDialog;
		openfile_trainClassification->Filter = "XML file|*.xml|All Files|*.*";
		if (openfile_trainClassification->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			char *fileNameTrainClassification = (char*)Marshal::StringToHGlobalAnsi(openfile_trainClassification->FileName).ToPointer();
			trainClassification = fileNameTrainClassification;
			chonse_pathTrainClass = true;
		}
	}
	private: System::Void btnImages_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openfile_trainImages = gcnew OpenFileDialog;
		openfile_trainImages->Filter = "XML file|*.XML|All Files|*.*";
		if (openfile_trainImages->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			char *fileNameTrainImages = (char*)Marshal::StringToHGlobalAnsi(openfile_trainImages->FileName).ToPointer();
			trainClassification = fileNameTrainImages;
			chonse_pathTrainimages = true;
		}
	}
	private: System::Void timer_controlRobot_Tick(System::Object^  sender, System::EventArgs^  e) {
		toa_do_t toa_do;
		labelDof1->Text = Convert::ToString(tBarDof1->Value);
		labelDof2->Text = Convert::ToString(tBarDof2->Value);
		labelDof3->Text = Convert::ToString(tBarDof3->Value);
		toa_do = pros_kineticsOfRobot(tBarDof1->Value, tBarDof2->Value, tBarDof2->Value + tBarDof3->Value);
		textBoxX->Text = Convert::ToString(toa_do.x);
		textBoxY->Text = Convert::ToString(toa_do.y);
		textBoxZ->Text = Convert::ToString(toa_do.z);
	}
	private: System::Void valueChangeDof1(System::Object^  sender, System::EventArgs^  e) {
		textBoxX->Text = "";
		textBoxY->Text = "";
		textBoxZ->Text = "";
		labelDof1->Text = Convert::ToString(tBarDof1->Value);
		array<unsigned char, 1> ^head1 = { 0x01, Convert::ToByte(labelDof1->Text) };
		serialPortCom->Write(head1, 0, head1->Length);
	}
	private: System::Void valueChangeDof2(System::Object^  sender, System::EventArgs^  e) {
		textBoxX->Text = "";
		textBoxY->Text = "";
		textBoxZ->Text = "";
		labelDof2->Text = Convert::ToString(tBarDof2->Value);
		array<unsigned char, 1> ^head2 = { 0x02, Convert::ToByte(labelDof2->Text) };
		serialPortCom->Write(head2, 0, head2->Length);
	}
	private: System::Void valueChangeDof3(System::Object^  sender, System::EventArgs^  e) {
		textBoxX->Text = "";
		textBoxY->Text = "";
		textBoxZ->Text = "";
		labelDof3->Text = Convert::ToString(tBarDof3->Value);
		array<unsigned char, 1> ^head3 = { 0x03, Convert::ToByte(labelDof3->Text) };
		serialPortCom->Write(head3, 0, head3->Length);
	}
	private: void tinh_toanGoc(float x, float y, float z)
	{
		goc_quay_t origin_des = reverse_kineticsOfRobot(x,y,z);;
		text->Text = Convert::ToString(origin_des.q1);
		text2->Text = Convert::ToString(origin_des.q2);
		text3->Text = Convert::ToString(origin_des.q3 - origin_des.q2);
		
		array<unsigned char, 1> ^origin_send_q1 = { 0x01, origin_des.q1 };
		serialPortCom->Write(origin_send_q1, 0, origin_send_q1->Length);
		array<unsigned char, 1> ^origin_send_q2 = { 0x02, origin_des.q2 };
		serialPortCom->Write(origin_send_q2, 0, origin_send_q2->Length);
		array<unsigned char, 1> ^origin_send_q3 = { 0x03, origin_des.q3 - origin_des.q2 };
		serialPortCom->Write(origin_send_q3, 0, origin_send_q3->Length);

	}
	private: goc_quay_t reverse_kineticsOfRobot(float x, float y, float z) {
		goc_quay_t goc_quay;
		float sin_q2;
		float cos_q2;
		float sin_q3;
		float cos_q3;
		goc_quay.q1 = atan2(y, x)*180/PI; // q1
		cos_q3 = (pow(x, 2) +pow(y, 2) + pow(z - d1, 2) - pow(a2, 2) - pow(a3, 2)) / (2 * a2 * a3);
		sin_q3 = sqrt(1 - pow(cos_q3,2));
		goc_quay.q3 = atan2(sin_q3, cos_q3)*180/PI; // q3
		cos_q2 = (x *(a2 + a3* cos_q3) - a3*(z - d1)*sin_q3*cos(atan2(y, x)))/(cos(atan2(y, x))*(pow(x,2)+pow(y,2)+pow(z - d1,2)));
		sin_q2 = sqrt(1 - pow(cos_q2, 2));
		goc_quay.q2 = atan2(sin_q2, cos_q2)*180/PI; // q2

		return goc_quay;
	}
	private: toa_do_t pros_kineticsOfRobot(float q1, float q2, float q3) {
		toa_do_t toa_do;
		toa_do.x = cos(q1*PI/180)*(a2*cos(q2*PI/180) + a3*cos((q2- q3)*PI/180));
		toa_do.y = sin(q1*PI/180)*(a2 * cos(q2*PI/180) + a3 * cos((q2 - q3)*PI/180));
		toa_do.z = a2 * sin(q2*PI/180) + a3 * sin((q2 - q3)*PI/180) + d1;
		return toa_do;
	}
	private: toa_do_t quy_dao(float t)
	{
		toa_do_t toa_do;
		toa_do.x =  5*t;//100+ 20*sin(t*PI/180) ;
		toa_do.y = 0 ;
		toa_do.z = 50;//100+ 20*cos(t*PI/180);
		return toa_do;
	}
	private: System::Void timerRobot_Tick(System::Object^  sender, System::EventArgs^  e) {
		toa_do_t p;
		p = quy_dao(time);
		tinh_toanGoc(p.x,p.y,p.z);
		if (time == 30)
		{
			inc = true;
		}
		if (time == 0)
		{
			inc = false;
		}
		if (inc)
		{
			time--;
		}
		else
		{
			time++;
		}

	}
	private: System::Void btnReverseKinetic_Click(System::Object^  sender, System::EventArgs^  e) {
		timerRobot->Start();

	}
	private: System::Void btnTest_Click(System::Object^  sender, System::EventArgs^  e) {
		timerRobot->Stop();
	}
		
};
}
