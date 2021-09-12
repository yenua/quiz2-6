#include <bangtal>
using namespace bangtal;

int main()
{
	auto room1 = Scene::create("룸1", "Images/배경-1.png");
	auto room2 = Scene::create("룸1", "Images/배경-2.png");
	auto door1 = Object::create("Images/문-오른쪽-닫힘.png", room1, 800, 270);
	auto door2 = Object::create("Images/똑똑.png", room2, 900, 270);
	auto closed1 = true;
	auto closed2 = 4;

	//룸1
	auto key = Object::create("Images/열쇠.png", room1, 600, 150);
	key->setScale(0.2f);
	key->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		object->pick();
		return true;
		});

	door1->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		if (closed1) {
			if (key->isHanded()) {
				object->setImage("Images/문-오른쪽-열림.png");
				closed1 = false;
			}
			else {
				showMessage("열쇠가 필요해~~~");
			}
		}
		else {
			startGame(room2);	//endGame();
		}
		return true;
		});

	//룸2
	auto display = Object::create("Images/디스플레이.png", room2, 300, 400);

	door2->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		if (closed2 > 2) {
			closed2--;
		}
		else if (closed2 ==2){
			object->setImage("Images/문-오른쪽-닫힘.png");
			closed2--;
		}
		else if (closed2==1) {
			object->setImage("Images/문-오른쪽-열림.png");
			closed2--;
		}
		else if (closed2 ==0) {
			endGame();
		}
		return true;
		});	

	startGame(room1);
}