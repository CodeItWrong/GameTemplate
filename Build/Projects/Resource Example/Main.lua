Objects = {}
Images = {}
Cameras = {}
Effects = {}
Sounds = {}
Meshes = {}
Music = {}
Files = {}
Emitters = {}
Sprites = {}
Matrixes = {}
Vectors = {}
Databases = {}
Lookups = {}
Memblocks = {}
Banks = {}
Coroutines = {}
Mutexes = {}
Animations = {}
Dll = {}
Threads = {}
ArrayFiles = {}
Items = {}

function NameObject(index, name)
	Objects[name] = index	
end

function NameImage(index, name)
	Images[name] = index	
end

function NameCamera(index, name)
	Cameras[name] = index	
end

function NameEffect(index, name)
	Effects[name] = index	
end

function NameSound(index, name)
	Sounds[name] = index	
end

function NameMesh(index, name)
	Meshes[name] = index	
end

function NameMusic(index, name)
	Music[name] = index	
end

function NameFile(index, name)
	Files[name] = index	
end

function NameEmitter(index, name)
	Emitters[name] = index	
end

function NameSprite(index, name)
	Sprites[name] = index	
end

function NameMatrix(index, name)
	Matrixes[name] = index	
end

function NameVector(index, name)
	Vectors[name] = index	
end

function NameDatabase(index, name)
	Databases[name] = index	
end

function NameLookup(index, name)
	Lookups[name] = index	
end

function NameMemblock(index, name)
	Memblocks[name] = index	
end

function NameBank(index, name)
	Banks[name] = index	
end

function NameCoroutine(index, name)
	Coroutines[name] = index	
end

function NameMutex(index, name)
	Mutexes[name] = index	
end

function NameAnimation(index, name)
	Animations[name] = index	
end

function NameDll(index, name)
	Dlls[name] = index	
end


function GetDll(name)
	return Dlls[name]
end

function GetObject(name)
	return Objects[name]
end

function GetImage(name)
	return Images[name]	
end

function GetCamera(name)
	return Cameras[name]	
end

function Effect(name)
	return Effects[name]	
end

function Sound(name)
	return Sounds[name]	
end

function Mesh(name)
	return Meshes[name]	
end

function GetMusic(name)
	return Music[name]	
end

function GetFile(name)
	return Files[name]
end

function GetEmitter(name)
	return Emitters[name]	
end

function GetSprite(name)
	return Sprites[name]	
end

function GetMatrix(name)
	return Matrixes[name]
end

function GetVector(name)
	return Vectors[name]	
end

function GetDatabase(name)
	return Databases[name]
end

function GetLookup(name)
	return Lookups[name]	
end

function GetMemblock(name)
	return Memblocks[name]	
end

function GetBank(name)
	return Banks[name] 	
end

function GetCoroutine(name)
	return Coroutines[name]	
end

function GetMutex(name)
	return Mutexes[name]	
end

function GetAnimation(name)
	return Animations[name]	
end

function AddThread(index, name)
	Threads[name] = index	
end

function GetThread(name)
	return Threads[name]
end

function FileAdd(index, name)
	ArrayFiles[name] = index	
end

function FileGet(name)
	return ArrayFiles[name]
end


function DeleteObject(name)
    Objects[name] = nil
end

function DeleteImage(name)
    Images[name] = nil
end

function DeleteEffect(name)
    Effects[name] = nil
end

function DeleteSound(name)
    Sounds[name] = nil
end

function DeleteMesh(name)
    Meshes[name] = nil
end

function DeleteMusic(name)
    Music[name] = nil
end

function DeleteFile(name)
    Files[name] = nil
end

function DeleteEmitter(name)
    Emitters[name] = nil
end

function DeleteSprite(name)
    Sprites[name] = nil
end

function DeleteMatirx(name)
    Matrixes[name] = nil
end

function DeleteVector(name)
    Vectors[name] = nil
end

function DeleteDatabase(name)
    Databases[name] = nil
end

function DeleteLookup(name)
    Lookups[name] = nil
end

function DeleteMemblock(name)
    Memblocks[name] = nil
end

function DeleteBank(name)
    Banks[name] = nil
end

function DeleteCoroutine(name)
    Coroutines[name] = nil
end

function DeleteMutex(name)
    Mutexes[name] = nil
end

function DeleteDll(name)
    Dlls[name] = nil
end

function DeleteAnimation(name)
    Animations[name] = nil
end

function DeleteThread(name)
    Threads[name] = nil
end

function DeleteArrayFile(name)
    ArrayFiles[name] = nil
end

function DeleteItem(name)
    Items[name] = nil
end

function GetItem(name)
	return Items[name] 	
end

function NameItem(index, name)
	Items[name] = index	
end