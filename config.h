#pragma once


//replace
#define secPerFrame 48 // 1 sec of simulation time is 48 sec of real time
#define geoDistance 42164000 // how far needs to be from the Earth
#define heightGravity -0.2244 // gravity for the GPS
#define geoSpeed 3100

#define GRAVITY -9.8067
#define PROJECTILE_SPEED 1000
#define HOURS_DAY 24
#define FPS 48
#define SPEED_OF_LIGHT 299792458
#define EARTH_FULL_ROTATION 60
#define M_PI 3.14159265358979323846
#define RADIUS_OF_EARTH 6378000
#define GEOSTATIONARY_ORBIT 42164000



class Config {
	public:
	Config() {};
	double getGravity() { return gravity; }
	double getProjectileSpeed() { return projectileSpeed; }
	double getHoursDay() { return hoursDay; }
	double getFrameRatePreSec() { return frameRatePreSec; }
	double getSpeedOfLight() { return speedOfLight; }
	double getEarthFullRotationSec() { return earthFullRotationSec; }
private:
	const double gravity = -9.8067;
	const double projectileSpeed = 1000;
	const double hoursDay = 24;
	const double frameRatePreSec = 30;
	const double speedOfLight = 299792458;
	const double earthFullRotationSec = 60;
};