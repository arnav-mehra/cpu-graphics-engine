#include "gui.hpp"
#include "ppc.hpp"
#include "scene.hpp"

using namespace std;

Scene* scene;

Scene::Scene() {
	scene = this;

	h = 480;
	w = 640;

	gui = new GUI();
	gui->show();
	ppc = new PPC();

	phong_exp = 1.0f;
	ambient = 1.0f;
	sm = 1U;
	
	// REQS
	//{
	//	bd = new BACKDROP("uffizi_cross.tiff");
	//}

	// EXTRA_CREDIT
	//{
	//	bd = new BACKDROP("panarama.tiff");
	//	MESH m;
	//	m.setAsGlass();
	//	m.fill = true;
	//	geometry.meshes.push_back(m);
	//}

	// ADDS BOX
	//{
	//	TEXTURE* tx = new TEXTURE("mineman.tiff");
	//	MESH m;
	//	m.setAsBox(V3(30.0f, -40.0f, -350.0f), tx, 20.0f, 20.0f, 20.0f);
	//	m.fix_normals();
	//	m.fill = true;
	//	geometry.meshes.push_back(m);
	//}

	// SPHERE
	//{
	//	TEXTURE* tx = new TEXTURE("ball.tiff");
	//	MESH m;
	//	m.setAsSphere(V3(80.0f, -40.0f, -300.0f), 12U, 10.0f, tx);
	//	m.fix_normals();
	//	m.fill = true;
	//	geometry.meshes.push_back(m);
	//}

	// ADD CAMERA VISUALIZATION
	//{
	//	PPC p;
	//	geometry.add_camera(p);
	//}

	// ADDS DOOR
	{
		TEXTURE* tx = new TEXTURE("door.tiff");
		tx->transform(true, false, false);
		MESH m;
		m.setAsBox(V3(0.0f, 0.0f, -300.0f), tx, 5.0f, 120.0f, 60.0f);
		m.fix_normals();
		m.fill = true;
		geometry.meshes.push_back(m);
	}

	// ADD 2ND LIGHT SOURCE
	{
		V3 center = V3(20.0f, -20.0f, -50.0f);
		V3 origin = V3(0.0f, 80.0f, 100.0f);
		LIGHT li = LIGHT(origin, center - origin, COLOR(255, 0, 0), DEG_TO_RAD(50.0f));
		geometry.lights.push_back(li);
	}

	// ADD 1ST LIGHT SOURCE
	{
		V3 center = V3(-10.0f, 18.0f, 18.0f);
		V3 origin = V3(0.0f, 60.0f, 110.0f);
		LIGHT li = LIGHT(origin, center - origin, COLOR(255, 0, 0), DEG_TO_RAD(40.0f));
		geometry.lights.push_back(li);
	}

	// SPHERE
	{
		MESH m;
		TEXTURE* tx = new TEXTURE("door.tiff");
		m.setAsFloor(tx);
		m.fix_normals();
		m.fill = true;
		geometry.meshes.push_back(m);
	}

	rotation_axis1 = V3(0.0f, -1.0f, -1.0f);
	rotation_axis2 = V3(0.0f, 1.0f, 1.0f);

	int u0 = 16, v0 = 40;
	fb = new FRAMEBUFFER(u0, v0, w, h);
	fb->position(u0, v0);
	fb->label("SW framebuffer");
	fb->show();
	fb->redraw();
	gui->uiw->position(u0 + w + u0, v0);	
}

void Scene::LoadTxtButton() {
	ppc->LoadTxt();
	fb->redraw();
}

void Scene::SaveTxtButton() {
	ppc->SaveAsTxt();
	fb->redraw();
}

void Scene::LoadBinButton() {
	geometry.meshes[SEL_MESH].LoadBin();
	fb->redraw();
}

void Scene::TeapotButton() {
	MESH m;
	m.Load334Bin();
	cout << "CENTER: " << m.get_center();
	geometry.meshes.push_back(m);
	fb->redraw();
}

void Scene::SaveBinButton() {
	geometry.meshes[SEL_MESH].SaveAsBin();
	fb->redraw();
}

void Scene::RotationButton() {
	geometry.meshes[SEL_MESH].rotate(rotation_axis1, rotation_axis2, 0.1f);
	fb->redraw();
}

void Scene::TransitionCamera() {
	fb->startThread();
}

void Scene::LightLeft() {
	geometry.lights[SEL_LIGHT].source[Dim::X] -= 5.0f;
	fb->redraw();
}

void Scene::LightRight() {
	geometry.lights[SEL_LIGHT].source[Dim::X] += 5.0f;
	fb->redraw();
}

void Scene::LightUp() {
	geometry.lights[SEL_LIGHT].source[Dim::Y] -= 5.0f;
	fb->redraw();
}

void Scene::LightDown() {
	geometry.lights[SEL_LIGHT].source[Dim::Y] += 5.0f;
	fb->redraw();
}

void Scene::LightFront() {
	geometry.lights[SEL_LIGHT].source[Dim::Z] += 5.0f;
	fb->redraw();
}

void Scene::LightBack() {
	geometry.lights[SEL_LIGHT].source[Dim::Z] -= 5.0f;
	fb->redraw();
}