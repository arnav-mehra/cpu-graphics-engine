// generated by Fast Light User Interface Designer (fluid) version 1.0304
#include "gui.hpp"
#include "scene.hpp"

void GUI::cb_LoadTxtButton_i(Fl_Button*, void*) {
    LoadTxtButton_cb();
}

void GUI::cb_LoadTxtButton(Fl_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_LoadTxtButton_i(o,v);
}

void GUI::cb_SaveTxtButton_i(Fl_Button*, void*) {
    SaveTxtButton_cb();
}

void GUI::cb_SaveTxtButton(Fl_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_SaveTxtButton_i(o, v);
}

void GUI::cb_LoadBinButton_i(Fl_Button*, void*) {
    LoadBinButton_cb();
}

void GUI::cb_LoadBinButton(Fl_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_LoadBinButton_i(o, v);
}

void GUI::cb_SaveBinButton_i(Fl_Button*, void*) {
    SaveBinButton_cb();
}

void GUI::cb_SaveBinButton(Fl_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_SaveBinButton_i(o, v);
}


void GUI::cb_TeapotButton_i(Fl_Button*, void*) {
    TeapotButton_cb();
}

void GUI::cb_TeapotButton(Fl_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_TeapotButton_i(o, v);
}


void GUI::cb_RotationButton_i(Fl_Button*, void*) {
    RotationButton_cb();
}

void GUI::cb_RotationButton(Fl_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_RotationButton_i(o, v);
}

void GUI::cb_Play_i(Fl_Return_Button*, void*) {
    Play_cb();
}

void GUI::cb_Play(Fl_Return_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_Play_i(o,v);
}

void GUI::cb_LightLeftButton_i(Fl_Return_Button*, void*) {
    LightLeftButton_cb();
}

void GUI::cb_LightLeftButton(Fl_Return_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_LightLeftButton_i(o, v);
}

void GUI::cb_LightRightButton_i(Fl_Return_Button*, void*) {
    LightRightButton_cb();
}

void GUI::cb_LightRightButton(Fl_Return_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_LightRightButton_i(o, v);
}

void GUI::cb_LightUpButton_i(Fl_Return_Button*, void*) {
    LightUpButton_cb();
}

void GUI::cb_LightUpButton(Fl_Return_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_LightUpButton_i(o, v);
}

void GUI::cb_LightDownButton_i(Fl_Return_Button*, void*) {
    LightDownButton_cb();
}

void GUI::cb_LightDownButton(Fl_Return_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_LightDownButton_i(o, v);
}

void GUI::cb_LightFrontButton_i(Fl_Return_Button*, void*) {
    LightFrontButton_cb();
}

void GUI::cb_LightFrontButton(Fl_Return_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_LightFrontButton_i(o, v);
}

void GUI::cb_LightBackButton_i(Fl_Return_Button*, void*) {
    LightBackButton_cb();
}

void GUI::cb_LightBackButton(Fl_Return_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_LightBackButton_i(o, v);
}

void GUI::cb_LightIncExponentButton_i(Fl_Return_Button*, void*) {
    LightIncExponentButton_cb();
}

void GUI::cb_LightIncExponentButton(Fl_Return_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_LightIncExponentButton_i(o, v);
}

void GUI::cb_LightDecExponentButton_i(Fl_Return_Button*, void*) {
    LightDecExponentButton_cb();
}

void GUI::cb_LightDecExponentButton(Fl_Return_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_LightDecExponentButton_i(o, v);
}

void GUI::cb_LightIncAmbientButton_i(Fl_Return_Button*, void*) {
    LightIncAmbientButton_cb();
}

void GUI::cb_LightIncAmbientButton(Fl_Return_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_LightIncAmbientButton_i(o, v);
}

void GUI::cb_LightDecAmbientButton_i(Fl_Return_Button*, void*) {
    LightDecAmbientButton_cb();
}

void GUI::cb_LightDecAmbientButton(Fl_Return_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_LightDecAmbientButton_i(o, v);
}

void GUI::cb_SM1Button_i(Fl_Return_Button*, void*) {
    SM1Button_cb();
}

void GUI::cb_SM1Button(Fl_Return_Button* o , void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_SM1Button_i(o, v);
}

void GUI::cb_SM2Button_i(Fl_Return_Button*, void*) {
    SM2Button_cb();
}

void GUI::cb_SM2Button(Fl_Return_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_SM2Button_i(o, v);
}

void GUI::cb_SM3Button_i(Fl_Return_Button*, void*) {
    SM3Button_cb();
}

void GUI::cb_SM3Button(Fl_Return_Button* o, void* v) {
    ((GUI*)(o->parent()->user_data()))->cb_SM3Button_i(o, v);
}

GUI::GUI() {
    {
        uiw = new Fl_Double_Window(400, 405, "GUI");
        uiw->user_data((void*)(this));
        {
            Fl_Button* o = new Fl_Button(15, 15, 150, 50, "Load Txt");
            o->selection_color(FL_DARK_RED);
            o->callback((Fl_Callback*)cb_LoadTxtButton);
        } // Fl_Button* o
        {
            Fl_Button* o = new Fl_Button(15, 80, 150, 50, "Save Txt");
            o->selection_color(FL_DARK_RED);
            o->callback((Fl_Callback*)cb_SaveTxtButton);
        } // Fl_Button* o
        {
            Fl_Button* o = new Fl_Button(15, 145, 150, 50, "Load Bin");
            o->selection_color(FL_DARK_RED);
            o->callback((Fl_Callback*)cb_LoadBinButton);
        } // Fl_Button* o
        {
            Fl_Button* o = new Fl_Button(15, 210, 150, 50, "Save Bin");
            o->selection_color(FL_DARK_RED);
            o->callback((Fl_Callback*)cb_SaveBinButton);
        } // Fl_Button* o
        
        {
            Fl_Button* o = new Fl_Button(200, 210, 150, 50, "Load Teapot");
            o->selection_color(FL_DARK_RED);
            o->callback((Fl_Callback*)cb_TeapotButton);
        } // Fl_Button* o

        {
            Fl_Button* o = new Fl_Button(15, 275, 150, 50, "Rotate Mesh");
            o->selection_color(FL_DARK_RED);
            o->callback((Fl_Callback*)cb_RotationButton);
        } // Fl_Button* o
        {
            Fl_Button* o = new Fl_Button(15, 340, 150, 50, "Play");
            o->callback((Fl_Callback*)cb_Play);
        } // Fl_Return_Button* o

        // MOVE LIGHT
        {
            Fl_Button* o = new Fl_Button(180, 55, 30, 30, "<");
            o->callback((Fl_Callback*)cb_LightLeftButton);
        } // Fl_Return_Button* o
        {
            Fl_Button* o = new Fl_Button(260, 55, 30, 30, ">");
            o->callback((Fl_Callback*)cb_LightRightButton);
        } // Fl_Return_Button* o
        {
            Fl_Button* o = new Fl_Button(220, 15, 30, 30, "^");
            o->callback((Fl_Callback*)cb_LightUpButton);
        } // Fl_Return_Button* o
        {
            Fl_Button* o = new Fl_Button(220, 95, 30, 30, "\/");
            o->callback((Fl_Callback*)cb_LightDownButton);
        } // Fl_Return_Button* o
        {
            Fl_Button* o = new Fl_Button(220, 45, 30, 30, "+");
            o->callback((Fl_Callback*)cb_LightFrontButton);
        } // Fl_Return_Button* o
        {
            Fl_Button* o = new Fl_Button(220, 65, 30, 30, "-");
            o->callback((Fl_Callback*)cb_LightBackButton);
        } // Fl_Return_Button* o

        {
            Fl_Button* o = new Fl_Button(200, 140, 80, 30, "+PhongExp");
            o->callback((Fl_Callback*)cb_LightIncExponentButton);
        } // Fl_Return_Button* o
        {
            Fl_Button* o = new Fl_Button(300, 140, 80, 30, "-PhongExp");
            o->callback((Fl_Callback*)cb_LightDecExponentButton);
        } // Fl_Return_Button* o
        {
            Fl_Button* o = new Fl_Button(200, 170, 80, 30, "+Ambient");
            o->callback((Fl_Callback*)cb_LightIncAmbientButton);
        } // Fl_Return_Button* o
        {
            Fl_Button* o = new Fl_Button(300, 170, 80, 30, "-Ambient");
            o->callback((Fl_Callback*)cb_LightDecAmbientButton);
        } // Fl_Return_Button* o

        {
            Fl_Button* o = new Fl_Button(200, 270, 30, 30, "SM1");
            o->callback((Fl_Callback*)cb_SM1Button);
        } // Fl_Return_Button* o
        {
            Fl_Button* o = new Fl_Button(240, 270, 30, 30, "SM2");
            o->callback((Fl_Callback*)cb_SM2Button);
        } // Fl_Return_Button* o
        {
            Fl_Button* o = new Fl_Button(280, 270, 30, 30, "SM3");
            o->callback((Fl_Callback*)cb_SM3Button);
        } // Fl_Return_Button* o
        uiw->end();
    } // Fl_Double_Window* uiw
}

int main(int argc, char **argv) {
    scene = new Scene;
    return Fl::run();
}

void GUI::show() {
    uiw->show();
}

void GUI::LoadTxtButton_cb() {
    scene->LoadTxtButton();
}

void GUI::SaveTxtButton_cb() {
    scene->SaveTxtButton();
}

void GUI::LoadBinButton_cb() {
    scene->LoadBinButton();
}

void GUI::SaveBinButton_cb() {
    scene->SaveBinButton();
}

void GUI::RotationButton_cb() {
    scene->RotationButton();
}

void GUI::Play_cb() {
    scene->TransitionCamera();
}

void GUI::LightLeftButton_cb() {
    scene->LightLeft();
}

void GUI::LightRightButton_cb() {
    scene->LightRight();
}

void GUI::LightUpButton_cb() {
    scene->LightUp();
}

void GUI::LightDownButton_cb() {
    scene->LightDown();
}

void GUI::LightFrontButton_cb() {
    scene->LightFront();
}

void GUI::LightBackButton_cb() {
    scene->LightBack();
}

void GUI::LightIncExponentButton_cb() {
    float& exp = scene->phong_exp;
    exp *= 2.0f;
    cout << "New Phong Exponent: " << exp << '\n';
    scene->geometry.meshes[SEL_MESH].set_phong_exp(exp);
    scene->fb->redraw();
}

void GUI::LightDecExponentButton_cb() {
    float& exp = scene->phong_exp;
    exp *= 0.5f;
    cout << "New Phong Exponent: " << exp << '\n';
    scene->geometry.meshes[SEL_MESH].set_phong_exp(exp);
    scene->fb->redraw();
}

void GUI::LightIncAmbientButton_cb() {
    float& amb = scene->ambient;
    amb = min(1.0f, amb + 0.02f);
    cout << "New Ambient: " << amb << '\n';
    scene->fb->redraw();
}

void GUI::LightDecAmbientButton_cb() {
    float& amb = scene->ambient;
    amb = max(0.0f, amb - 0.02f);
    cout << "New Ambient: " << amb << '\n';
    scene->fb->redraw();
}

void GUI::SM1Button_cb() {
    scene->sm = 1;
    scene->fb->redraw();
}

void GUI::SM2Button_cb() {
    scene->sm = 2;
    scene->fb->redraw();
}

void GUI::SM3Button_cb() {
    scene->sm = 3;
    scene->fb->redraw();
}

void GUI::TeapotButton_cb() {
    scene->TeapotButton();
    scene->fb->redraw();
}