var canvas = document.getElementById("myCanva").getContext("2d");
const canva3d = document.getElementById("myCanva3D").getContext("2d");
const murColor = "#0f0";
const squareSize = 50;

const map =
"0000000000000000\n0    0     0   0\n0     0        0\n0         0    0\n0              0\n0      0   0   0\n0              0\n0       0      0\n0              0\n0       0      0\n0              0\n0       00     0\n0              0\n0              0\n0000000000000000\n"

function fillSquare(x, y, c = squareSize) {
	canvas.fillRect(x, y, c, c);
}

function printMap(map) {
	let m = map.split("\n")
	let arr = [];
	for (let i = 0; i < m.length; i++) {
		for (let j = 0; j < m[i].length; j++) {
			if (m[i][j] == "0") {
				fillSquare(j * squareSize, i * squareSize);
				arr.push([j*squareSize, (j+1) * squareSize, i*squareSize, (i +1)* squareSize])
			}
		}
	}
	return arr
}

function isCollide(x, y, cmap) {
	for (let i = 0; i < cmap.length; i++) {
		if (x >= cmap[i][0] && x <= cmap[i][1] && y >= cmap[i][2] && y <= cmap [i][3])
			return true
	}
	return false;
}

function getCollideColor(x, y, cmap) {
	//return 'green'
	for (let i = 0; i < cmap.length; i++) {
		if (x >= cmap[i][0] && x <= cmap[i][1] && y >= cmap[i][2] && y <= cmap [i][3]) {
			if (x <= cmap[i][0] + 1)
				return 'yellow'
			if (x >= cmap[i][1] - 1)
				return 'grey'
			if (y <= cmap[i][2] + 1)
				return 'blue'
			if (y >= cmap[i][3] - 1)
				return 'pink'
			return 'green'
		}
	}
	return 'green';
}

function raytrace(px, py, num, rot, coallision, squareSize = 2) {
	let tmp = canvas.fillStyle;
	let tmp3d = canva3d.fillStyle
	canvas.fillStyle = 'red';
	canva3d.fillStyle = murColor;
	let height = canva3d.canvas.height;
	let width = canva3d.canvas.width;
	for (let i = -num/2; i < num/2; i++) {
		for (let j = 0; j < 1000; j++) {
			let y = j * Math.sin((i+rot)*Math.PI / 180)
			let x = j * Math.cos((i+rot)*Math.PI/180)
			if (isCollide(px+x, py+y, coallision)) {
				let xx = (num/2 + i) * 10
				if (height-j > 0) {
					let col = getCollideColor(px+x, py+y, coallision)
					canva3d.fillStyle = col
					canva3d.fillRect(xx, height/2 - (height-j)/2, 10, height - j)
					break;
				}
			}
			if (j == 30 || i ==-num/2 || i == num/2-1)
				fillSquare(px + x, py + y, squareSize);
		}
	}
	canvas.fillStyle = tmp;
	canva3d.fillStyle = tmp3d
}

function affiche(x, y, fov, rot) {
	canvas.fillStyle = "#000";
	canva3d.fillStyle = "#000";
	canvas.fillRect(0, 0, canvas.canvas.width, canvas.canvas.height);
	canva3d.fillRect(0, 0, canva3d.canvas.width, canva3d.canvas.height);
	canvas.fillStyle = murColor
	canva3d.fillStyle = murColor
	let coallision = printMap(map);
	raytrace(x, y, fov, rot, coallision)
	return coallision
}
let r = 0, mx = 0, my = 0;
let co;
co = affiche(251, 160, 80, 0);
setInterval(()=> {
	return
	let mtmp = mx;
	if (!isCollide(251+mx+1, 160+my, co))mx++;
	if (!isCollide(251+mtmp, 163+my, co))my += 3;
	affiche(251+mx, 160+my, 80, r)
	r += 5
}, 100)

var player_x = 251;
var player_y = 160;
var player_r=0
function move(key, step, cmap) {
	let x=player_x, y=player_y
	if (key == "L") {
		x = player_x+step;
		y = player_y;
	} else if (key == "R") {
		x = player_x-step;
		y = player_y;
	} else if (key == "U") {
		x = player_x
		y = player_y-step
	} else if (key == "D") {
		x = player_x
		y = player_y+step
	}else if(key=="RG")
		player_r+=3;
	else if(key =="RD")
		player_r-=3
	if (!isCollide(x, y, cmap)) {
		player_x = x;
		player_y = y;
		affiche(player_x, player_y, 80, player_r)
	}
}

const getId = (id)=>document.getElementById(id)


getId("b1").addEventListener("click", ()=> {
	move("L", 5, co)
})
getId("b2").addEventListener("click", ()=> {
	move("R", 5, co)
})
getId("b3").addEventListener("click", ()=> {
	move("U", 5, co)
})
getId("b4").addEventListener("click", ()=> {
	move("D", 5, co);
})
getId("b5").addEventListener("click", ()=> {
	move("RG", 5, co);
})
getId("b6").addEventListener("click", ()=> {
	move("RD", 5, co);
})