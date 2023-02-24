/*
 * This class allows complete encapsulation of the program
 *
 * The user need only add a shape via the pattern shown in the
 * examples below, modifying properties (p) and the texture;
 * the ShapeBuilder class will handle the vertex calculations
 * and mesh construction
 *
 */



#include "SceneBuilder.h"
#include "ShapeBuilder.h"
#include "Mesh.h"

using namespace std;

void SceneBuilder::UBuildScene(vector<GLMesh>& scene)
{

	///BUILDING A SHAPE:
	///To build a shape, follow the following standard:
	///
	///		GLMesh <glmesh_name>
	///		<glmesh_name>.p = {
	///		red float, green float, blue float, alpha float,
	///		x scale float, y scale float, z scale float,
	///		x rotation degrees float, 1.0f, 0.0f, 0.0f,
	///		y rotation degrees float, 0.0f, 1.0f, 0.0f,
	///		z rotation degrees float, 0.0f, 0.0f, 1.0f,
	///		x translate float, y translate float, z translate float,
	///		x texture scale float, y texture scale float
	///		};
	///		<glmesh_name>.texFilename = "textures\\[filename.filetype]";
	///		<glmesh_name>.length = float;
	///		<glmesh_name>.height = float;
	///		<glmesh_name>.radius = float;
	///		<glmesh_name>.number_of_sides = float;
	///		ShapeBuilder::<ShapeBuilderMethod>(<glmesh_name>);
	///		scene.push_back(<glmesh_name>);



	//CIRCLE BOTTOM OF CUP
	GLMesh cir_mesh_01;
	cir_mesh_01.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		2.0f,	2.0f,	2.0f,
		0.0f,	1.0f,	0.0f,	0.0f,
		-90.0f,	0.0f,	1.0f,	0.0f,
		-90.0f,	0.0f,	0.0f,	1.0f,
		0.0f,	0.0f,	5.0f,
		1.0f,	1.0f
	};
	cir_mesh_01.texFilename = "texture\\black.png";
	cir_mesh_01.radius = 0.5f;
	cir_mesh_01.number_of_sides = 144.0f;
	ShapeBuilder::UBuildCircle(cir_mesh_01);
	scene.push_back(cir_mesh_01);

	//CIRCLE COFFEE LINE IN CUP
	GLMesh cir_mesh_02;
	cir_mesh_02.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		2.0f,	2.0f,	2.0f,
		0.0f,	1.0f,	0.0f,	0.0f,
		-90.0f,	0.0f,	1.0f,	0.0f,
		-90.0f,	0.0f,	0.0f,	1.0f,
		0.0f,	1.8f,	5.0f,
		1.0f,	1.0f
	};
	cir_mesh_02.texFilename = "texture\\coffee1.png";
	cir_mesh_02.radius = 0.5f;
	cir_mesh_02.number_of_sides = 144.0f;
	ShapeBuilder::UBuildCircle(cir_mesh_02);
	scene.push_back(cir_mesh_02);

	//MUG
	GLMesh hollow_cyl;
	hollow_cyl.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		2.0f,	2.0f,	2.0f,
		0.0f,	1.0f,	0.0f,	0.0f,
		-90.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		2.0f,	0.0f,	5.0f,
		1.0f,	1.0f
	};
	hollow_cyl.texFilename = "texture\\mug.png";
	hollow_cyl.innerRadius = 0.45f;
	hollow_cyl.radius = 0.5f;
	hollow_cyl.height = 1.0f;
	hollow_cyl.number_of_sides = 144.0f;
	ShapeBuilder::UBuildHollowCylinder(hollow_cyl);
	scene.push_back(hollow_cyl);

	// HANDLE
	GLMesh handle;
	handle.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		2.0f,	2.0f,	2.0f,
		90.0f,	1.0f,	0.0f,	0.0f,
		0.0f,	0.0f,	1.0f,	0.0f,
		90.0f,	0.0f,	0.0f,	1.0f,
		1.1f,	2.0f,	6.0f,
		1.0f,	1.0f
	};
	handle.texFilename = "texture\\black.png";
	handle.innerRadius = 0.3f;
	handle.radius = 0.4f;
	handle.height = 0.1f;
	handle.number_of_sides = 144.0f;
	ShapeBuilder::UBuildHollowCylinder(handle);
	scene.push_back(handle);

	//PLANE
	GLMesh plane_mesh;
	plane_mesh.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		6.0f,	0.0f,	10.0f,
		0.0f,	1.0f,	0.0f,	0.0f,
		0.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		2.0f,	0.0f,	0.0f,
		1.0f,	1.0f
	};
	plane_mesh.texFilename = "texture\\wood1.png";
	ShapeBuilder::UBuildPlane(plane_mesh);
	scene.push_back(plane_mesh);

	//LAPTOP
	GLMesh laptop1;
	laptop1.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		5.0f,	0.1f,	8.0f,
		0.0f,	1.0f,	0.0f,	0.0f,
		10.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		0.0f,	0.0f,	-1.0f,
		1.0f,	1.0f
	};
	laptop1.texFilename = "texture\\laptop.png";
	ShapeBuilder::UBuildCube(laptop1);
	scene.push_back(laptop1);

	//LAPTOP Texture
	GLMesh lap_tex;
	lap_tex.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		4.0f,	0.0f,	2.5f,
		0.0f,	1.0f,	0.0f,	0.0f,
		-80.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		0.0f,	0.1009f,	-1.0f,
		1.0f,	1.0f
	};
	lap_tex.texFilename = "texture\\laptop.png";
	ShapeBuilder::UBuildPlane(lap_tex);
	scene.push_back(lap_tex);

	//LAMP BASE
	GLMesh base;
	base.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		1.0f,	1.0f,	1.0f,
		-90.0f,	1.0f,	0.0f,	0.0f,
		0.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		3.0f,	0.0f,	-6.0f,
		1.0f,	1.0f
	};
	base.texFilename = "texture\\silver.png";
	base.radius = 1.0f;
	base.length = 0.3f;
	base.number_of_sides = 144.0f;
	ShapeBuilder::UBuildCylinder(base);
	scene.push_back(base);

	//LAMP
	GLMesh lamp;
	lamp.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		1.0f,	1.0f,	1.0f,
		-90.0f,	1.0f,	0.0f,	0.0f,
		0.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		3.0f,	0.3f,	-6.0f,
		1.0f,	1.0f
	};
	lamp.texFilename = "texture\\white.png";
	lamp.radius = 1.0f;
	lamp.length = 3.5f;
	lamp.number_of_sides = 144.0f;
	ShapeBuilder::UBuildCylinder(lamp);
	scene.push_back(lamp);

	//LAMP TOUCH BUTTON
	GLMesh button;
	button.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		1.0f,	1.0f,	1.0f,
		-90.0f,	1.0f,	0.0f,	0.0f,
		0.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		3.0f,	0.3f,	-6.0f,
		1.0f,	1.0f
	};
	button.texFilename = "texture\\silver.png";
	button.radius = 0.6f;
	button.length = 3.51f;
	button.number_of_sides = 144.0f;
	ShapeBuilder::UBuildCylinder(button);
	scene.push_back(button);

	//PENCIL HOLDER SECTION
	GLMesh pencil_holder1;
	pencil_holder1.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		0.8f,	1.6f,	1.6f,
		0.0f,	1.0f,	0.0f,	0.0f,
		0.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		5.5f,	0.001f,	-1.0f,
		1.0f,	1.0f
	};
	pencil_holder1.texFilename = "texture\\Marble1.jpg";
	ShapeBuilder::UBuildOpenCube(pencil_holder1);
	scene.push_back(pencil_holder1);

	//PENCIL HOLDER SECTION
	GLMesh pencil_holder2;
	pencil_holder2.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		0.8f,	0.5f,	1.6f,
		0.0f,	1.0f,	0.0f,	0.0f,
		0.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		4.699f,	0.001f,	-1.0f,
		1.0f,	1.0f
	};
	pencil_holder2.texFilename = "texture\\Marble1.jpg";
	ShapeBuilder::UBuildOpenCube(pencil_holder2);
	scene.push_back(pencil_holder2);

	//PENCIL HOLDER SECTION
	GLMesh pencil_holder3;
	pencil_holder3.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		1.6f,	0.8f,	1.6f,
		0.0f,	1.0f,	0.0f,	0.0f,
		-90.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		5.1f,	0.001f,	0.601f,
		1.0f,	1.0f
	};
	pencil_holder3.texFilename = "texture\\Marble1.jpg";
	ShapeBuilder::UBuildOpenCube2(pencil_holder3);
	scene.push_back(pencil_holder3);

	//STICKY NOTE PAD
	GLMesh sticky_note;
	sticky_note.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		1.2f,	0.2f,	1.2f,
		0.0f,	1.0f,	0.0f,	0.0f,
		0.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		5.1f,	0.001f,	0.601f,
		1.0f,	1.0f
	};
	sticky_note.texFilename = "texture\\Pad.png";
	ShapeBuilder::UBuildCube(sticky_note);
	scene.push_back(sticky_note);

	GLMesh top_note;
	top_note.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		0.6f,	0.0f,	0.6f,
		0.0f,	1.0f,	0.0f,	0.0f,
		-90.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		5.1f,	0.202f,	0.601f,
		1.0f,	1.0f
	};
	top_note.texFilename = "texture\\note.png";
	ShapeBuilder::UBuildPlane(top_note);
	scene.push_back(top_note);

	//PAPERCLIPS
	GLMesh clips;
	clips.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		0.79f,	0.0f,	.39f,
		0.0f,	1.0f,	0.0f,	0.0f,
		-90.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		4.699f,	0.3f,	-1.0f,
		1.0f,	1.0f
	};
	clips.texFilename = "texture\\paperclips.png";
	ShapeBuilder::UBuildPlane(clips);
	scene.push_back(clips);

	//PENCIL
	GLMesh pencil1;
	pencil1.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		0.5f,	0.5f,	1.0f,
		-110.0f,	1.0f,	0.0f,	0.0f,
		0.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		5.0f,	0.1f,	-0.94f,
		1.0f,	1.0f
	};
	pencil1.texFilename = "texture\\pencil.png";
	pencil1.radius = 0.1f;
	pencil1.length = 2.5f;
	pencil1.number_of_sides = 6.0f;
	ShapeBuilder::UBuildCylinder(pencil1);
	scene.push_back(pencil1);

	//PENCIL ERASER
	GLMesh eraser_tip;
	eraser_tip.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		0.5f,	0.5f,	1.0f,
		-110.0f,	1.0f,	0.0f,	0.0f,
		0.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		5.0f,	2.3f,	-1.74f,
		1.0f,	1.0f
	};
	eraser_tip.texFilename = "texture\\pencil_eraser.png";
	eraser_tip.radius = 0.102f;
	eraser_tip.length = 0.2f;
	eraser_tip.number_of_sides = 100.0f;
	ShapeBuilder::UBuildCylinder(eraser_tip);
	scene.push_back(eraser_tip);

	GLMesh eraser_tip2;
	eraser_tip2.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		0.5f,	0.5f,	1.0f,
		-110.0f,	1.0f,	0.0f,	0.0f,
		0.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		5.0f,	2.45f,	-1.7947f,
		1.0f,	1.0f
	};
	eraser_tip2.texFilename = "texture\\pink.png";
	eraser_tip2.radius = 0.1023f;
	eraser_tip2.length = 0.05f;
	eraser_tip2.number_of_sides = 100.0f;
	ShapeBuilder::UBuildCylinder(eraser_tip2);
	scene.push_back(eraser_tip2);

	//Highlighter
	GLMesh highlighter;
	highlighter.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		0.5f,	0.5f,	1.0f,
		60.0f,	1.0f,	0.0f,	0.0f,
		170.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		5.7f,	0.1f,	-1.13f,
		1.0f,	1.0f
	};
	highlighter.texFilename = "texture\\highlighter.png";
	highlighter.radius = 0.16f;
	highlighter.length = 2.2f;
	highlighter.number_of_sides = 100.0f;
	ShapeBuilder::UBuildCylinder(highlighter);
	scene.push_back(highlighter);

	//Cap
	GLMesh cap;
	cap.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		0.5f,	0.5f,	1.0f,
		60.0f,	1.0f,	0.0f,	0.0f,
		170.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		5.985f,	1.5f,	-1.94f,
		1.0f,	1.0f
	};
	cap.texFilename = "texture\\highlighter2.png";
	cap.radius = 0.165f;
	cap.length = 0.7f;
	cap.number_of_sides = 100.0f;
	ShapeBuilder::UBuildCylinder(cap);
	scene.push_back(cap);

	GLMesh clip;
	clip.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		0.08f,	0.02f,	0.5f,
		60.0f,	1.0f,	0.0f,	0.0f,
		170.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		5.795f,	1.94f,	-2.02f,
		1.0f,	1.0f
	};
	clip.texFilename = "texture\\black.png";
	ShapeBuilder::UBuildCube(clip);
	scene.push_back(clip);


}

